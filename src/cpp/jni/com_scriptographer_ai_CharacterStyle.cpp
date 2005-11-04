#include "StdHeaders.h"
#include "ScriptographerEngine.h"
#include "aiGlobals.h"
#include "com_scriptographer_ai_CharacterStyle.h"

/*
 * com.scriptographer.ai.CharacterStyle
 */

using namespace ATE;

/*
 * java.lang.Object clone()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_clone(JNIEnv *env, jobject obj) {
	try {
		CharFeaturesRef features = gEngine->getCharFeaturesRef(env, obj);
		CharFeaturesRef clone;
		if (!sCharFeatures->Clone(features, &clone))
			return gEngine->wrapCharFeaturesRef(env, clone, NULL);
	} EXCEPTION_CONVERT(env)
	return NULL;
}

/*
 * void nativeFetch(int handle)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_nativeFetch(JNIEnv *env, jobject obj, jint handle) {
	try {
		AIPathStyle style;
		AIPathStyleMap map;

		if (!sAIATEPaint->GetAIPathStyleAndMap((CharFeaturesRef) handle, &style, &map))
			PathStyle_init(env, obj, &style, &map);
		
		// TODO: define nativeFetch
	} EXCEPTION_CONVERT(env)
}

/*
 * void nativeCommit(int handle1, int handle2,
			float[] fillColor, boolean hasFillColor, short fillOverprint,
			float[] strokeColor, boolean hasStrokeColor, short strokeOverprint, float strokeWidth,
			float dashOffset, float[] dashArray,
			short cap, short join, float miterLimit,
			short clip, short lockClip, short evenOdd, float resolution)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_nativeCommit(JNIEnv *env, jobject obj, jint handle1, jint handle2, jfloatArray fillColor, jboolean hasFillColor, jshort fillOverprint, jfloatArray strokeColor, jboolean hasStrokeColor, jshort strokeOverprint, jfloat strokeWidth, jfloat dashOffset, jfloatArray dashArray, jshort cap, jshort join, jfloat miterLimit, jshort clip, jshort lockClip, jshort evenOdd, jfloat resolution) {
	try {
		AIPathStyle style;
		AIPathStyleMap map;
		PathStyle_convertPathStyle(env, &style, &map, fillColor, hasFillColor, fillOverprint, strokeColor, hasStrokeColor, strokeOverprint, strokeWidth, dashOffset, dashArray, cap, join, miterLimit, clip, lockClip, evenOdd, resolution);
		sAIATEPaint->GetCharFeatures(&style, &map, (CharFeaturesRef) handle1);
		if (handle2 != 0)
			sTextRange->SetLocalCharFeatures((TextRangeRef) handle2, (CharFeaturesRef) handle1);
	} EXCEPTION_CONVERT(env)
}

/*
 * void nativeSetStyle(int handle1, int handle2)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_nativeSetStyle(JNIEnv *env, jobject obj, jint handle1, jint handle2) {
	try {
		sTextRange->SetLocalCharFeatures((TextRangeRef) handle2, (CharFeaturesRef) handle1);
	} EXCEPTION_CONVERT(env)
}

/*
 * void finalize()
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_finalize(JNIEnv *env, jobject obj) {
	try {
		sCharFeatures->Release(gEngine->getCharFeaturesRef(env, obj));
	} EXCEPTION_CONVERT(env)
}

/*
 * java.lang.Float getFontSize()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getFontSize(JNIEnv *env, jobject obj) {
	STYLE_GET_FLOAT(FontSize)
}

/*
 * void setFontSize(java.lang.Float value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setFontSize(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_FLOAT(FontSize)
}

/*
 * java.lang.Float getHorizontalScale()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getHorizontalScale(JNIEnv *env, jobject obj) {
	STYLE_GET_FLOAT(HorizontalScale)
}

/*
 * void setHorizontalScale(java.lang.Float value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setHorizontalScale(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_FLOAT(HorizontalScale)
}

/*
 * java.lang.Float getVerticalScale()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getVerticalScale(JNIEnv *env, jobject obj) {
	STYLE_GET_FLOAT(VerticalScale)
}

/*
 * void setVerticalScale(java.lang.Float value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setVerticalScale(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_FLOAT(VerticalScale)
}

/*
 * java.lang.Boolean getAutoLeading()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getAutoLeading(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(AutoLeading)
}

/*
 * void setAutoLeading(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setAutoLeading(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(AutoLeading)
}

/*
 * java.lang.Float getLeading()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getLeading(JNIEnv *env, jobject obj) {
	STYLE_GET_FLOAT(Leading)
}

/*
 * void setLeading(java.lang.Float value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setLeading(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_FLOAT(Leading)
}

/*
 * java.lang.Integer getTracking()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getTracking(JNIEnv *env, jobject obj) {
	STYLE_GET_INTEGER(Tracking)
}

/*
 * void setTracking(java.lang.Integer value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setTracking(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_INTEGER(Tracking)
}

/*
 * java.lang.Float getBaselineShift()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getBaselineShift(JNIEnv *env, jobject obj) {
	STYLE_GET_FLOAT(BaselineShift)
}

/*
 * void setBaselineShift(java.lang.Float value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setBaselineShift(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_FLOAT(BaselineShift)
}

/*
 * java.lang.Float getRotation()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getRotation(JNIEnv *env, jobject obj) {
	STYLE_GET_FLOAT(CharacterRotation)
}

/*
 * void setRotation(java.lang.Float value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setRotation(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_FLOAT(CharacterRotation)
}

/*
 * java.lang.Integer getKerningMethod()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getKerningMethod(JNIEnv *env, jobject obj) {
	STYLE_GET_ENUM(AutoKernType)
}

/*
 * void setKerningMethod(java.lang.Integer value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setKerningMethod(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_ENUM(AutoKernType)
}

/*
 * java.lang.Integer getCapitalization()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getCapitalization(JNIEnv *env, jobject obj) {
	STYLE_GET_ENUM(FontCapsOption)
}

/*
 * void setCapitalization(java.lang.Integer value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setCapitalization(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_ENUM(FontCapsOption)
}

/*
 * java.lang.Integer getBaselineOption()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getBaselineOption(JNIEnv *env, jobject obj) {
	STYLE_GET_ENUM(FontBaselineOption)
}

/*
 * void setBaselineOption(java.lang.Integer value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setBaselineOption(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_ENUM(FontBaselineOption)
}

/*
 * java.lang.Integer getOpenTypePosition()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getOpenTypePosition(JNIEnv *env, jobject obj) {
	STYLE_GET_ENUM(FontOpenTypePositionOption)
}

/*
 * void setOpenTypePosition(java.lang.Integer value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setOpenTypePosition(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_ENUM(FontOpenTypePositionOption)
}

/*
 * java.lang.Integer getStrikethroughPosition()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getStrikethroughPosition(JNIEnv *env, jobject obj) {
	STYLE_GET_ENUM(StrikethroughPosition)
}

/*
 * void setStrikethroughPosition(java.lang.Integer value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setStrikethroughPosition(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_ENUM(StrikethroughPosition)
}

/*
 * java.lang.Integer getUnderlinePosition()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getUnderlinePosition(JNIEnv *env, jobject obj) {
	STYLE_GET_ENUM(UnderlinePosition)
}

/*
 * void setUnderlinePosition(java.lang.Integer value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setUnderlinePosition(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_ENUM(UnderlinePosition)
}

/*
 * java.lang.Float getUnderlineOffset()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getUnderlineOffset(JNIEnv *env, jobject obj) {
	STYLE_GET_FLOAT(UnderlineOffset)
}

/*
 * void setUnderlineOffset(java.lang.Float value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setUnderlineOffset(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_FLOAT(UnderlineOffset)
}

/*
 * java.lang.Boolean getLigature()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getLigature(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(Ligature)
}

/*
 * void setLigature(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setLigature(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(Ligature)
}

/*
 * java.lang.Boolean getDiscretionaryLigature()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getDiscretionaryLigature(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(DiscretionaryLigatures)
}

/*
 * void setDiscretionaryLigature(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setDiscretionaryLigature(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(DiscretionaryLigatures)
}

/*
 * java.lang.Boolean getContextualLigature()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getContextualLigature(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(ContextualLigatures)
}

/*
 * void setContextualLigature(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setContextualLigature(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(ContextualLigatures)
}

/*
 * java.lang.Boolean getAlternateLigatures()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getAlternateLigatures(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(AlternateLigatures)
}

/*
 * void setAlternateLigatures(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setAlternateLigatures(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(AlternateLigatures)
}

/*
 * java.lang.Boolean getOldStyle()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getOldStyle(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(OldStyle)
}

/*
 * void setOldStyle(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setOldStyle(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(OldStyle)
}

/*
 * java.lang.Boolean getFractions()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getFractions(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(Fractions)
}

/*
 * void setFractions(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setFractions(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(Fractions)
}

/*
 * java.lang.Boolean getOrdinals()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getOrdinals(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(Ordinals)
}

/*
 * void setOrdinals(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setOrdinals(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(Ordinals)
}

/*
 * java.lang.Boolean GetSwash()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_GetSwash(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(Swash)
}

/*
 * void setSwash(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setSwash(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(Swash)
}

/*
 * java.lang.Boolean getTitling()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getTitling(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(Titling)
}

/*
 * void setTitling(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setTitling(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(Titling)
}

/*
 * java.lang.Boolean getConnectionForms()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getConnectionForms(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(ConnectionForms)
}

/*
 * void setConnectionForms(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setConnectionForms(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(ConnectionForms)
}

/*
 * java.lang.Boolean getStylisticAlternates()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getStylisticAlternates(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(StylisticAlternates)
}

/*
 * void setStylisticAlternates(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setStylisticAlternates(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(StylisticAlternates)
}

/*
 * java.lang.Boolean getOrnaments()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getOrnaments(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(Ornaments)
}

/*
 * void setOrnaments(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setOrnaments(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(Ornaments)
}

/*
 * java.lang.Integer getFigureStyle()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getFigureStyle(JNIEnv *env, jobject obj) {
	STYLE_GET_ENUM(FigureStyle)
}

/*
 * void setFigureStyle(java.lang.Integer value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setFigureStyle(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_ENUM(FigureStyle)
}

/*
 * java.lang.Boolean getNoBreak()
 */
JNIEXPORT jobject JNICALL Java_com_scriptographer_ai_CharacterStyle_getNoBreak(JNIEnv *env, jobject obj) {
	STYLE_GET_BOOLEAN(NoBreak)
}

/*
 * void setNoBreak(java.lang.Boolean value)
 */
JNIEXPORT void JNICALL Java_com_scriptographer_ai_CharacterStyle_setNoBreak(JNIEnv *env, jobject obj, jobject value) {
	STYLE_SET_BOOLEAN(NoBreak)
}