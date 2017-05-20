#include <jni.h>
#include <memory>

#include "speedDrive/gamestate.h"

#include "speedDrive/assetManager/assetManager.h"
#include "speedDrive/appLogicManager/appLogicManager.h"
#include "speedDrive/renderer/renderer.h"

static std::unique_ptr<AssetManager> assetManager;
static std::unique_ptr<AppLogicManager> appLogicManager;
static std::unique_ptr<Renderer> renderer;

extern "C" { // todo: GLSurfaceView onPause, onResume, onExit, handle half-blood activity
    JNIEXPORT void JNICALL
    Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceCreated(JNIEnv *env, jclass cls) {
        appLogicManager = std::make_unique<AppLogicManager>(assetManager.get());
        renderer = std::make_unique<Renderer>(appLogicManager->getViewController());
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
        assetManager = std::make_unique<AssetManager>(env, aMng);
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

