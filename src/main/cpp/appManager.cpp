#include <jni.h>

#include <GLES2/gl2.h>
extern "C" {
    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceCreated(JNIEnv *env,
                                                                                jclass cls) {
        glClearColor(0.8f, 0.5f, 0.9f, 0.0f);
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceChanged(JNIEnv *env, jclass cls,
                                                                                jint w, jint h) {
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onDrawFrame(JNIEnv *env, jclass cls) {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}