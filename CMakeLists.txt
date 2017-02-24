cmake_minimum_required(VERSION 3.4.1)

#add_library(app-glue STATIC
#            ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")


# Import the CMakeLists.txt for the glm library
add_subdirectory(src/main/cpp/glm)

include_directories(src/main/cpp/customDefines.h)
add_library(appManager SHARED
             src/main/cpp/appManager.cpp
              src/main/cpp/shaderProgram.cpp)


#target_include_directories(appManager PRIVATE
#                           ${ANDROID_NDK}/sources/android/cpufeatures
#                           ${ANDROID_NDK}/sources/android/native_app_glue
#                           ${ndk_helper_dir})

target_link_libraries( # Specifies the target library.
                       appManager
                       android
                       log
                       EGL
                       GLESv2
                       glm
                       #z # for libpng
                       )
