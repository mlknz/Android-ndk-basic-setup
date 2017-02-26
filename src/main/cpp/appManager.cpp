#include <jni.h>

#include <GLES2/gl2.h>

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <math.h>
#include <png.h>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "common.h"

#include "assetManager/assetManager.h"
#include "gamestate.h"
#include "assetManager/pngImageLoader.h"
#include "renderer/renderer.h"
#include "appLogicManager/appLogicManager.h"

static GameState* gameState;
static AppLogicManager* appLogic;
static Renderer* renderer;
static AAssetManager* assetManager;

extern "C" {
    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceCreated(JNIEnv *env, jclass cls) {
        gameState = new GameState();

        appLogic = new AppLogicManager(gameState);
        renderer = new Renderer();
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceChanged(JNIEnv *env, jclass cls,
                                                                                jint w, jint h) {
        renderer->resize(w, h);
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onDrawFrame(JNIEnv *env, jclass cls) {
        appLogic->update();
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

        delete [] fileContent;

    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchStart(JNIEnv *env, jclass cls, float posX) {

    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchMove(JNIEnv *env, jclass cls) {
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchEnd(JNIEnv *env, jclass cls) {
    }
}

