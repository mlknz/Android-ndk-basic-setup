#Android C++ NDK App

Playing with gl context and C++ with android.

${ANDROID_NDK} is NDK root directory (Android/sdk/ndk-bundle for me). 

Mess with libpng installation:

1. add ${ANDROID_NDK} to global $PATH variable (at ~/.bashrc or etc/environment)
2. git clone https://github.com/julienr/libpng-android.git to ${ANDROID_NDK}/sources/android
3. fix lib bug locally: number 130 in pngpriv.h from `define PNG_ARM_NEON_OPT 2` to `define PNG_ARM_NEON_OPT 0`.
3. compile the lib with script from repo: ./build.sh
4. (not needed since it is done) add to CMakeLists.txt:
```bash
add_library(libpng STATIC IMPORTED)
set_target_properties(libpng PROPERTIES IMPORTED_LOCATION
    ${ANDROID_NDK}/sources/android/libpng-android/obj/local/${ANDROID_ABI}/libpng.a)
target_include_directories(appManager PRIVATE ${ANDROID_NDK}/sources/android/libpng-android/jni)
```
and add `libpng` and `z` to `target_link_libraries`
