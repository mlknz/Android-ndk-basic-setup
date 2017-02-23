#include <jni.h>

#include <GLES2/gl2.h>
#include <sys/time.h>
#include <android/log.h>
#include <math.h>

#include "NDKHelper.h"

long long currentTimeInMilliseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
double col = 0.0;
double x = 1;
extern "C" {
    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceCreated(JNIEnv *env,
                                                                                jclass cls) {
        glClearColor(0.8, 0.5f, 0.9f, 0.0f);
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceChanged(JNIEnv *env, jclass cls,
                                                                                jint w, jint h) {
        x = w;
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onDrawFrame(JNIEnv *env, jclass cls) {
        double t = currentTimeInMilliseconds();

        glClearColor(col, col, col, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchStart(JNIEnv *env, jclass cls, float posX) {
        col = posX / x;
        __android_log_print(ANDROID_LOG_VERBOSE, "TestApp", "The value of 1 + 1 is %d", 1+1);
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchMove(JNIEnv *env, jclass cls) {
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchEnd(JNIEnv *env, jclass cls) {
    }
}

