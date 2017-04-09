#include "assetManager.h"

#include "../common.h"


AssetManager::AssetManager(JNIEnv* env, jobject aMng) {
    this->env = env;
    this->aMng = aMng;

    env->NewGlobalRef(aMng);
    this->refreshFromJava();
}

AssetManager::~AssetManager() {
    this->env = nullptr;
    this->aMng = nullptr;
}

void AssetManager::refreshFromJava() {
    this->assetManager = AAssetManager_fromJava(this->env, this->aMng);
}

// todo: refactor
ImageData* AssetManager::loadPNGImage(std::string path) {
    return FromAssetPNGFile(this->assetManager, path.c_str());
}

char* AssetManager::loadFile(std::string path) {
    AAsset* file = AAssetManager_open(this->assetManager, path.c_str(), AASSET_MODE_BUFFER);
    size_t fileLength = AAsset_getLength(file);

    char* fileContent = new char[fileLength + 1]; // todo: remove new

    AAsset_read(file, fileContent, fileLength);
    fileContent[fileLength] = '\0';
    return fileContent;
}