#ifndef __AssetManager__
#define __AssetManager__

#include <jni.h>

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#include <string>

class AssetManager {
public:
    AssetManager(JNIEnv* env, jobject aMng);
    ~AssetManager();
    void refreshFromJava();
    char* loadFile(std::string path);

private:
    JNIEnv* env;
    jobject aMng;

    AAssetManager* assetManager;
};
#endif