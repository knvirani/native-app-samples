//
// Created by kunjeshvirani on 26/2/17.
//

#ifndef BLANKNATIVEACTIVITY_NEW_LOG_H
#define BLANKNATIVEACTIVITY_NEW_LOG_H

#include <android/log.h>

#define LOG_WARN(x...) __android_log_print(ANDROID_LOG_WARN, "Warning: ", x)
#define LOG_INFO(x...) __android_log_print(ANDROID_LOG_INFO, "Info: ", x)
#define LOG_ERROR(x...) __android_log_print(ANDROID_LOG_ERROR, "Error: ", x)
#define LOG_VERBOSE(x...) __android_log_print(ANDROID_LOG_VERBOSE, "Verbose: ", x)




#endif //BLANKNATIVEACTIVITY_NEW_LOG_H
