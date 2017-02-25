#ifndef __CustomDefines__
#define __CustomDefines__

#include <android/log.h>

#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,"TestApp",__VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,"TestApp",__VA_ARGS__)

#endif
