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
add_library(appManager SHARED
              src/main/cpp/appManager.cpp
              src/main/cpp/gamestate.cpp

              src/main/cpp/appLogicManager/appLogicManager.cpp

              src/main/cpp/sceneManager/sceneManager.cpp

              src/main/cpp/assetManager/assetManager.cpp
              src/main/cpp/assetManager/pngImageLoader.cpp

              src/main/cpp/renderer/renderer.cpp
              src/main/cpp/renderer/shaderProgram.cpp
              src/main/cpp/renderer/texture.cpp

              src/main/cpp/gameObject/gameObject.cpp
              src/main/cpp/gameObject/button.cpp

              src/main/cpp/viewController/view.cpp
              src/main/cpp/viewController/viewController.cpp
              src/main/cpp/viewController/views/chooseLevelView.cpp
              src/main/cpp/viewController/views/gameView.cpp
              src/main/cpp/viewController/views/levelPackView.cpp
              src/main/cpp/viewController/views/loadingView.cpp
              src/main/cpp/viewController/views/mainMenuView.cpp
              src/main/cpp/viewController/views/settingsView.cpp
              src/main/cpp/viewController/views/startUpView.cpp
              )

target_include_directories(appManager PRIVATE ${ANDROID_NDK}/sources/android/libpng-android/jni/)
target_include_directories(appManager PRIVATE ${ANDROID_NDK}/sources/android/freetype2-static/include/)

target_link_libraries( # Specifies the target library.
                       appManager

                       android
                       log
                       EGL
                       GLESv2
                       freetype
                       glm
                       libpng
                       z
                       )
