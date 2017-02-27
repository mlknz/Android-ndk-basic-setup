#include <jni.h>

#include "gamestate.h"

#include "assetManager/assetManager.h"
#include "appLogicManager/appLogicManager.h"
#include "renderer/renderer.h"
#include "sceneManager/sceneManager.h"

static GameState* gameState;

static AssetManager* assetManager;
static AppLogicManager* appLogicManager;
static Renderer* renderer;
static SceneManager* sceneManager;

extern "C" {
    JNIEXPORT void JNICALL
    Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceCreated(JNIEnv *env, jclass cls) {
        gameState = new GameState();
        sceneManager = new SceneManager();

        appLogicManager = new AppLogicManager(gameState, assetManager, sceneManager);
        renderer = new Renderer(gameState, sceneManager);

        appLogicManager->switchToMenuScene();
    }

    JNIEXPORT void JNICALL
    Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceChanged(JNIEnv *env, jclass cls, jint w, jint h) {
        renderer->resize(w, h);
    }

    JNIEXPORT void JNICALL
    Java_mlkn_testapp_GameLibJNIWrapper_onDrawFrame(JNIEnv *env, jclass cls) {
        appLogicManager->update();
        renderer->render();
    }

    JNIEXPORT void JNICALL
    Java_mlkn_testapp_GameLibJNIWrapper_passAssetManager(JNIEnv *env, jclass cls, jobject aMng) {
        assetManager = new AssetManager(env, aMng);
    }

    JNIEXPORT void JNICALL
    Java_mlkn_testapp_GameLibJNIWrapper_onTouchStart(JNIEnv *env, jclass cls, float posX, float posY) {
        appLogicManager->onTouchStart(posX, posY);
    }

    JNIEXPORT void JNICALL
    Java_mlkn_testapp_GameLibJNIWrapper_onTouchMove(JNIEnv *env, jclass cls, float posX, float posY) {
        appLogicManager->onTouchMove(posX, posY);
    }

    JNIEXPORT void JNICALL
    Java_mlkn_testapp_GameLibJNIWrapper_onTouchEnd(JNIEnv *env, jclass cls, float posX, float posY) {
        appLogicManager->onTouchEnd(posX, posY);
    }
}

