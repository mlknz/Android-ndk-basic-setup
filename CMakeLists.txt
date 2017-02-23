cmake_minimum_required(VERSION 3.4.1)

#add_library(app-glue STATIC
#            ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#set(ndk_helper_dir src/main/libs/ndk_helper)
#add_subdirectory(${ndk_helper_dir} ndk_helper)

add_library(appManager SHARED
            src/main/cpp/customDefines.cpp # todo: make it header only
             src/main/cpp/appManager.cpp
              src/main/cpp/shaderProgram.cpp)


#target_include_directories(appManager PRIVATE
#                           ${ANDROID_NDK}/sources/android/cpufeatures
#                           ${ANDROID_NDK}/sources/android/native_app_glue
#                           ${ndk_helper_dir})

target_link_libraries( # Specifies the target library.
                       appManager
                       android
                       #app-glue
                       log
                       EGL
                       GLESv2
                       #ndk-helper
                       )
