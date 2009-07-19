/*
 * Scriptographer
 *
 * This file is part of Scriptographer, a Plugin for Adobe Illustrator.
 *
 * Copyright (c) 2002-2008 Juerg Lehni, http://www.scratchdisk.com.
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
 * File created on 03.01.2005.
 *
 * $Id$
 */

package com.scriptographer.ui;

import java.util.EnumSet;

import com.scriptographer.ScriptographerEngine; 
import com.scratchdisk.script.Callable;
import com.scratchdisk.util.IntegerEnumUtils;

/**
 * @author lehni
 * 
 * @jshide
 */
public abstract class TextEditItem<S> extends TextValueItem {

	private boolean unitInitialized = false;

	protected TextEditItem(Dialog dialog, int handle) {
		super(dialog, handle);
	}
	
	/**
	 * For subclasses
	 * 
	 * @param dialog
	 * @param type
	 * @param options
	 */
	protected TextEditItem(Dialog dialog, ItemType type, EnumSet<TextOption> options) {
		super(dialog, type, IntegerEnumUtils.getFlags(options));
	}
	
	protected TextEditItem(Dialog dialog, EnumSet<TextOption> options) {
		// filter out the pseudo styles from the options:
		// (max. real bit is 3, and the mask is (1 << (max + 1)) - 1
		this(dialog, getType(options), options);
	}

	private static ItemType getType(EnumSet<TextOption> options) {
		if (options != null) {
			// abuse the ADM's password style for creating it as a type...
			if (options.contains(TextOption.PASSWORD)) {
				return ItemType.TEXT_EDIT_PASSWORD;
			} else if (options.contains(TextOption.POPUP)) {
				return options.contains(TextOption.SCROLLING) ? ItemType.TEXT_EDIT_SCROLLING_POPUP
						: ItemType.TEXT_EDIT_POPUP;
			} else {
				boolean multiline = (options.contains(TextOption.MULTILINE));
				if (options.contains(TextOption.READONLY)) {
					return multiline ? ItemType.TEXT_EDIT_MULTILINE_READONLY
							: ItemType.TEXT_EDIT_READONLY;
				} else if (multiline) {
					return ItemType.TEXT_EDIT_MULTILINE;
				}
			}
		}
		return ItemType.TEXT_EDIT;
	}

	public void setValue(float value) {
		super.setValue(value);
		// By default we don't want units to be shown, but this only
		// works when the text edit is actually used for values,
		// otherwise it would directly be forced into value mode...
		// So only set it to false if it is for values, and only once.
		if (!unitInitialized) {
			this.setShowUnits(false);
			unitInitialized = true;
		}
	}

	public abstract S getStyle();

	public abstract void setStyle(S style);

	/*
	 * Callback functions
	 */
	
	// TODO: are all these really needed?
	
	private Callable onPreCut = null;

	public Callable getOnPreCut() {
		return onPreCut;
	}

	public void setOnPreCut(Callable onPreCut) {
		this.onPreCut = onPreCut;
	}

	protected void onPreCut() throws Exception {
		if (onPreCut != null)
			ScriptographerEngine.invoke(onPreCut, this);
	}
	
	private Callable onCut = null;

	public Callable getOnCut() {
		return onCut;
	}

	public void setOnCut(Callable onCut) {
		this.onCut = onCut;
	}

	protected void onCut() throws Exception {
		if (onCut != null)
			ScriptographerEngine.invoke(onCut, this);
	}

	private Callable onPreCopy = null;

	public Callable getOnPreCopy() {
		return onPreCopy;
	}

	public void setOnPreCopy(Callable onPreCopy) {
		this.onPreCopy = onPreCopy;
	}

	protected void onPreCopy() throws Exception {
		if (onPreCopy != null)
			ScriptographerEngine.invoke(onPreCopy, this);
	}

	private Callable onCopy = null;

	public Callable getOnCopy() {
		return onCopy;
	}

	public void setOnCopy(Callable onCopy) {
		this.onCopy = onCopy;
	}

	protected void onCopy() throws Exception {
		if (onCopy != null)
			ScriptographerEngine.invoke(onCopy, this);
	}

	private Callable onPrePaste = null;

	public Callable getOnPrePaste() {
		return onPrePaste;
	}

	public void setOnPrePaste(Callable onPrePaste) {
		this.onPrePaste = onPrePaste;
	}

	protected void onPrePaste() throws Exception {
		if (onPrePaste != null)
			ScriptographerEngine.invoke(onPrePaste, this);
	}

	private Callable onPaste = null;

	public Callable getOnPaste() {
		return onPaste;
	}

	public void setOnPaste(Callable onPaste) {
		this.onPaste = onPaste;
	}

	protected void onPaste() throws Exception {
		if (onPaste != null)
			ScriptographerEngine.invoke(onPaste, this);
	}

	private Callable onPreClear = null;

	public Callable getOnPreClear() {
		return onPreClear;
	}

	public void setOnPreClear(Callable onPreClear) {
		this.onPreClear = onPreClear;
	}

	protected void onPreClear() throws Exception {
		if (onPreClear != null)
			ScriptographerEngine.invoke(onPreClear, this);
	}

	private Callable onClear = null;

	public Callable getOnClear() {
		return onClear;
	}

	public void setOnClear(Callable onClear) {
		this.onClear = onClear;
	}

	protected void onClear() throws Exception {
		if (onClear != null)
			ScriptographerEngine.invoke(onClear, this);
	}
	
	private Callable onPreSelectionChange = null;

	public Callable getOnPreSelectionChange() {
		return onPreSelectionChange;
	}

	public void setOnPreSelectionChange(Callable onPreSelectionChange) {
		this.onPreSelectionChange = onPreSelectionChange;
	}

	protected void onPreSelectionChange() throws Exception {
		if (onPreSelectionChange != null)
			ScriptographerEngine.invoke(onPreSelectionChange, this);
	}

	private Callable onSelectionChange = null;

	public Callable getOnSelectionChange() {
		return onSelectionChange;
	}

	public void setOnSelectionChange(Callable onSelectionChange) {
		this.onSelectionChange = onSelectionChange;
	}

	protected void onSelectionChange() throws Exception {
		if (onSelectionChange != null)
			ScriptographerEngine.invoke(onSelectionChange, this);
	}
	private Callable onPreRedo = null;

	public Callable getOnPreRedo() {
		return onPreRedo;
	}

	public void setOnPreRedo(Callable onPreRedo) {
		this.onPreRedo = onPreRedo;
	}

	protected void onPreRedo() throws Exception {
		if (onPreRedo != null)
			ScriptographerEngine.invoke(onPreRedo, this);
	}

	private Callable onRedo = null;

	public Callable getOnRedo() {
		return onRedo;
	}

	public void setOnRedo(Callable onRedo) {
		this.onRedo = onRedo;
	}

	protected void onRedo() throws Exception {
		if (onRedo != null)
			ScriptographerEngine.invoke(onRedo, this);
	}

	private Callable onPreUndo = null;

	public Callable getOnPreUndo() {
		return onPreUndo;
	}

	public void setOnPreUndo(Callable onPreUndo) {
		this.onPreUndo = onPreUndo;
	}

	protected void onPreUndo() throws Exception {
		if (onPreUndo != null)
			ScriptographerEngine.invoke(onPreUndo, this);
	}

	private Callable onUndo = null;

	public Callable getOnUndo() {
		return onUndo;
	}

	public void setOnUndo(Callable onUndo) {
		this.onUndo = onUndo;
	}

	protected void onUndo() throws Exception {
		if (onUndo != null)
			ScriptographerEngine.invoke(onUndo, this);
	}
	
	protected void onNotify(Notifier notifier, ListEntry entry) throws Exception {
		switch (notifier) {
			case PRE_CLIPBOARD_CUT:
				onPreCut();
				break;
			case POST_CLIPBOARD_CUT:
				onCut();
				break;
			case PRE_CLIPBOARD_COPY:
				onPreCopy();
				break;
			case POST_CLIPBOARD_COPY:
				onCopy();
				break;
			case PRE_CLIPBOARD_PASTE:
				onPrePaste();
				break;
			case POST_CLIPBOARD_PASTE:
				onPaste();
				break;
			case PRE_CLIPBOARD_CLEAR:
				onPreClear();
				break;
			case POST_CLIPBOARD_CLEAR:
				onClear();
				break;
			case PRE_TEXT_SELECTION_CHANGED:
				onPreSelectionChange();
				break;
			case TEXT_SELECTION_CHANGED:
				onSelectionChange();
				break;
			case PRE_CLIPBOARD_REDO:
				onPreRedo();
				break;
			case POST_CLIPBOARD_REDO:
				onRedo();
				break;
			case PRE_CLIPBOARD_UNDO:
				onPreUndo();
				break;
			case POST_CLIPBOARD_UNDO:
				onUndo();
				break;
		}
	}

	/* 
	 * text edits
	 * 
	 */

	public void setStringValue(Object value) {
		if (value != null)
			setText(value.toString());
	}
	
	public String getStringValue() {
		return getText();
	}

	public native int getPrecision();
	public native void setPrecision(int precision);
		
	public native void setMaxLength(int length);
	public native int getMaxLength();

	/**
	 * @jshide
	 */
	public native void setSelection(int start, int end);
	public native int[] getSelection();
	public native void selectAll();
	
	public void setSelection(int[] range) {
		setSelection(range[0], range[1]);
	}
	
	public void setSelection(int pos) {
		setSelection(pos, pos);
	}

	/*
	 * Needed for a workaround on CS4, Mac. See native code.
	 */
	@SuppressWarnings("unused")
	private int setSelectionTimer = 0;

	public native void setAllowMath(boolean allowMath);
	public native boolean getAllowMath();
	
	public native void setAllowUnits(boolean allowUnits);
	public native boolean getAllowUnits();

	/*
	 *  child items
	 */
	private static final int
		ITEM_TEXTEDIT = 3,
		ITEM_POPUP = 4;

	private TextEdit textEdit;
	private PopupList popupList;
	
	public TextEdit getTextEdit() {
		if (textEdit == null) {
			int handle = getChildItemHandle(ITEM_TEXTEDIT);
			textEdit = handle != 0 ? new TextEdit(dialog, handle) : null;
		}
		return textEdit;
	}
	
	public PopupList getPopupList() {
		if (popupList == null) {
			int handle = getChildItemHandle(ITEM_POPUP);
			popupList = handle != 0 ? new PopupList(dialog, handle) : null;
		}
		return popupList;
	}
}
