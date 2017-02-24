cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

# Import the CMakeLists.txt for the glm library
add_subdirectory(src/main/cpp/glm)

add_library(libpng STATIC IMPORTED)
set_target_properties(libpng PROPERTIES IMPORTED_LOCATION
    ${ANDROID_NDK}/sources/android/libpng-android/obj/local/${ANDROID_ABI}/libpng.a)

include_directories(src/main/cpp/customDefines.h)
add_library(appManager SHARED
             src/main/cpp/appManager.cpp
              src/main/cpp/shaderProgram.cpp)

target_include_directories(appManager PRIVATE ${ANDROID_NDK}/sources/android/libpng-android/jni/)

target_link_libraries( # Specifies the target library.
                       appManager

                       android
                       libpng
                       z
                       log
                       EGL
                       GLESv2
                       glm
                       )
