/*
 * Scriptographer
 *
 * This file is part of Scriptographer, a Plugin for Adobe Illustrator.
 *
 * Copyright (c) 2002-2005 Juerg Lehni, http://www.scratchdisk.com.
 * All rights reserved.
 *
 * Please visit http://scriptographer.com/ for updates and contact.
 *
 * -- GPL LICENSE NOTICE --
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 * -- GPL LICENSE NOTICE --
 *
 * $RCSfile: loadJava.cpp,v $
 * $Author: lehni $
 * $Revision: 1.2 $
 * $Date: 2005/07/31 12:09:53 $
 */
 
 #include "stdHeaders.h"
#include "ScriptographerEngine.h"
#include "loadJava.h"
#include <sys/stat.h>

#define JRE_KEY "Software\\JavaSoft\\Java Runtime Environment"

void getJVMPath(const char *jrePath, const char *jvmType, char *jvmPath) {
	struct stat s;
	sprintf(jvmPath, "%s\\bin\\%s\\jvm.dll" , jrePath, jvmType);
	if (stat(jvmPath, &s) != 0)
		throw new StringException("No JVM of type `%s' found at `%s'", jvmType, jvmPath);
}

bool getStringFromRegistry(HKEY key, const char *name, char *buf, jint bufsize) {
	DWORD type, size;
	return (RegQueryValueEx(key, name, 0, &type, 0, &size) == 0
		&& type == REG_SZ
		&& (size < (unsigned int)bufsize)
		&& RegQueryValueEx(key, name, 0, 0, (unsigned char*) buf, &size) == 0);
}

void getJREPath(char *jrePath) {
	HKEY key, subkey;

	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, JRE_KEY, 0, KEY_READ, &key) != 0)
		throw new StringException("Error opening registry key '" JRE_KEY);

	char version[64];
	if (!getStringFromRegistry(key, "CurrentVersion", version, sizeof(version))) {
		RegCloseKey(key);
		throw new StringException("Failed to read registry key '" JRE_KEY "\\CurrentVersion'");
	}

	if (RegOpenKeyEx(key, version, 0, KEY_READ, &subkey) != 0) {
		RegCloseKey(key);
		throw new StringException("Error opening registry key '" JRE_KEY "\\%s'", version);
	}

	if (!getStringFromRegistry(subkey, "JavaHome", jrePath, MAX_PATH)) {
		RegCloseKey(key);
		RegCloseKey(subkey);
		throw new StringException("Failed to read registry key '" JRE_KEY "\\%s\\JavaHome'", version);
	}

	RegCloseKey(key);
	RegCloseKey(subkey);
}

void loadJavaVM(const char *jvmType, CreateJavaVMProc *createJavaVM, GetDefaultJavaVMInitArgsProc *getDefaultJavaVMInitArgs) {
    char jrePath[MAX_PATH];
	getJREPath(jrePath);

	char jvmPath[MAX_PATH];
	getJVMPath(jrePath, jvmType, jvmPath);

	// load the Java VM DLL
	HINSTANCE handle = LoadLibrary(jvmPath);

	if (handle == NULL)
		throw new StringException("Cannot load JVM at %s", jvmPath);

	// now get the function addresses
	*createJavaVM = (CreateJavaVMProc) GetProcAddress(handle, "JNI_CreateJavaVM");
	*getDefaultJavaVMInitArgs = (GetDefaultJavaVMInitArgsProc) GetProcAddress(handle, "JNI_GetDefaultJavaVMInitArgs");

	if (createJavaVM == NULL || getDefaultJavaVMInitArgs == NULL)
		throw new StringException("Cannot find JNI interfaces in: %s", jvmPath);
}
