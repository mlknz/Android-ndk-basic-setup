#ifndef __AppManager__
#define __AppManager__

#include <jni.h>

extern "C" {
JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceCreated(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceChanged(JNIEnv* env, jclass cls, jint w, jint h);
JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onDrawFrame(JNIEnv* env, jclass cls);

JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchStart(JNIEnv* env, jclass cls, float posX);
JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchMove(JNIEnv* env, jclass cls);
JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchEnd(JNIEnv* env, jclass cls);
};
#endif
