#include <jni.h>

#include "assetManager/assetManager.h"
#include "gamestate.h"
#include "renderer/renderer.h"
#include "appLogicManager/appLogicManager.h"

static GameState* gameState;

static AssetManager* assetManager;
static AppLogicManager* appLogic;
static Renderer* renderer;

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
        assetManager = new AssetManager(env, aMng);
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchStart(JNIEnv *env, jclass cls, float posX) {

    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchMove(JNIEnv *env, jclass cls) {
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchEnd(JNIEnv *env, jclass cls) {
    }
}

