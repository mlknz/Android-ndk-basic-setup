#Android C++ NDK App

Playing with gl context and C++ with android.

To launch this project you need to setup these static libs (some guidance below):
1. [glm](http://glm.g-truc.net/0.9.8/index.html)
2. [libpng](http://www.libpng.org/pub/png/libpng.html)
3. [freetype2](https://www.freetype.org/) 

How to setup libs:

1. relevant info about build and expected paths could be found at CMakeLists.txt
2. add ${ANDROID_NDK} (NDK root dir) to global $PATH variable (at ~/.bashrc or etc/environment). I am using ndk-r13b currently.
3. download and cross-compile libs with `ndk-build` for [different Android ABI's](https://developer.android.com/ndk/guides/abis.html). Some configuring is has to be done before building, currently I am using these repackages: [libpng](https://github.com/mlknz/libpng-android), [freetype2](https://github.com/cdave1/freetype2-android).


