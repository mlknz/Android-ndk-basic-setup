#include "assetManager.h"

#include "../common.h"
#include "pngImageLoader.h"

AssetManager::AssetManager(JNIEnv* env, jobject aMng) {
    this->env = env;
    this->aMng = aMng;

    env->NewGlobalRef(aMng);
    this->refreshFromJava();

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

AssetManager::~AssetManager() {
    this->env = nullptr;
    this->aMng = nullptr;
}

void AssetManager::refreshFromJava() {
    this->assetManager = AAssetManager_fromJava(this->env, this->aMng);
}