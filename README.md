#Android C++ NDK App

Playing with gl context and C++ in android.

${ANDROID_NDK} is NDK root directory (Android/sdk/ndk-bundle for me). 

libpng installation:
0. add ${ANDROID_NDK} to global $PATH variable (at ~/.bashrc or etc/environment)
1. git clone https://github.com/julienr/libpng-android.git to ${ANDROID_NDK}/sources/android
2. compile the lib with script from repo: ./build.sh
3. (not needed since it is done) add to CMakeLists.txt:
```bash
add_library(libpng STATIC IMPORTED)
set_target_properties(libpng PROPERTIES IMPORTED_LOCATION
    ${ANDROID_NDK}/sources/android/libpng-android/obj/local/armeabi/libpng.a)
target_include_directories(appManager PRIVATE ${ANDROID_NDK}/sources/android/libpng-android/jni)
```
also add `libpng` and `z` to `target_link_libraries`
