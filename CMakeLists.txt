cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

add_library(glm STATIC ${ANDROID_NDK}/sources/android/glm/detail/glm.cpp)
add_library(freetype STATIC IMPORTED)
add_library(libpng STATIC IMPORTED)

set_target_properties(freetype PROPERTIES IMPORTED_LOCATION
    ${ANDROID_NDK}/sources/android/freetype2-static/Android/obj/local/${ANDROID_ABI}/libfreetype2-static.a)
set_target_properties(libpng PROPERTIES IMPORTED_LOCATION
    ${ANDROID_NDK}/sources/android/libpng-android/obj/local/${ANDROID_ABI}/libpng.a)

include_directories(src/main/cpp/common.h src/main/cpp/config.h ${ANDROID_NDK}/sources/android/glm/..)
add_library(speedDrive SHARED
              src/main/cpp/appManager.cpp
              src/main/cpp/speedDrive/gamestate.cpp

              src/main/cpp/speedDrive/appLogicManager/appLogicManager.cpp

              src/main/cpp/speedDrive/sceneManager/sceneManager.cpp

              src/main/cpp/speedDrive/assetManager/assetManager.cpp
              src/main/cpp/speedDrive/assetManager/pngImageLoader.cpp

              src/main/cpp/speedDrive/renderer/renderer.cpp
              src/main/cpp/speedDrive/renderer/shaderProgram.cpp
              src/main/cpp/speedDrive/renderer/texture.cpp

              src/main/cpp/speedDrive/gameObject/gameObject.cpp
              src/main/cpp/speedDrive/gameObject/button.cpp

              src/main/cpp/speedDrive/viewController/view.cpp
              src/main/cpp/speedDrive/viewController/viewController.cpp
              src/main/cpp/speedDrive/viewController/views/chooseLevelView.cpp
              src/main/cpp/speedDrive/viewController/views/gameView.cpp
              src/main/cpp/speedDrive/viewController/views/levelPackView.cpp
              src/main/cpp/speedDrive/viewController/views/loadingView.cpp
              src/main/cpp/speedDrive/viewController/views/mainMenuView.cpp
              src/main/cpp/speedDrive/viewController/views/settingsView.cpp
              src/main/cpp/speedDrive/viewController/views/startUpView.cpp
              )

target_include_directories(speedDrive PRIVATE ${ANDROID_NDK}/sources/android/libpng-android/jni/)
target_include_directories(speedDrive PRIVATE ${ANDROID_NDK}/sources/android/freetype2-static/include/)

target_link_libraries( # Specifies the target library.
                       speedDrive

                       android
                       log
                       EGL
                       GLESv2
                       freetype
                       glm
                       libpng
                       z
                       )
