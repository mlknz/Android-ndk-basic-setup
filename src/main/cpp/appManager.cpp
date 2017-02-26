#include <jni.h>

#include <GLES2/gl2.h>
#include <sys/time.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <math.h>
#include <png.h>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "assetManager/assetManager.h"
#include "assetManager/pngImageLoader.h"
#include "renderer/renderer.h"

#include "common.h"
#include "renderer/shaderProgram.h"

static Renderer* renderer;
static AAssetManager* assetManager;

long long currentTimeInMilliseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
double col = 0.0;
double x = 1;

extern "C" {
    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceCreated(JNIEnv *env, jclass cls) {
        renderer = new Renderer();
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceChanged(JNIEnv *env, jclass cls,
                                                                                jint w, jint h) {
        renderer->resize(w, h);
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onDrawFrame(JNIEnv *env, jclass cls) {
        double t = currentTimeInMilliseconds();
        renderer->render();
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_passAssetManager(JNIEnv *env, jclass cls,
                                                                                jobject aMng) {

        env->NewGlobalRef(aMng);
        assetManager = AAssetManager_fromJava(env, aMng);

        ImageData* testImage;
        testImage = FromAssetPNGFile(assetManager, "textures/testImage2.png");
        LOGI("image width / height: %d / %d", testImage->img_width, testImage->img_height);

        AAsset* file = AAssetManager_open(assetManager, "shaders/test.vert", AASSET_MODE_BUFFER);
        size_t fileLength = AAsset_getLength(file);

        char* fileContent = new char[fileLength + 1];

        AAsset_read(file, fileContent, fileLength);
        fileContent[fileLength] = '\0';

        // use file content
        GLuint sh = compileShader(GL_VERTEX_SHADER, fileContent);

        delete [] fileContent;

    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchStart(JNIEnv *env, jclass cls, float posX) {

    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchMove(JNIEnv *env, jclass cls) {
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchEnd(JNIEnv *env, jclass cls) {
    }
}

