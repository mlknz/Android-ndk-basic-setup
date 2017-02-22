#include <jni.h>

#include <GLES2/gl2.h>
#include <sys/time.h>
#include <math.h>

long long currentTimeInMilliseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
double col = 0.0, col2 = 0.5, col3 = 0.9;
extern "C" {
    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceCreated(JNIEnv *env,
                                                                                jclass cls) {
        glClearColor(0.8, 0.5f, 0.9f, 0.0f);
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceChanged(JNIEnv *env, jclass cls,
                                                                                jint w, jint h) {
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onDrawFrame(JNIEnv *env, jclass cls) {
        double t = currentTimeInMilliseconds();

        glClearColor(col, col2, col3, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        col =(sin(t/1000.) + 1.) / 2.0;
        col2 = 0.5;
        col3 = 0.9;
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchStart(JNIEnv *env, jclass cls) {
        col = 1.0;
    }
    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchMove(JNIEnv *env, jclass cls) {
        col2 = 1.0;
    }
    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchEnd(JNIEnv *env, jclass cls) {
        col3 = 0.0;
    }
}

