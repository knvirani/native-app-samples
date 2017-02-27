
####### CMake Build script by KV
####### Created on 27 february, 2017

cmake_minimum_required(VERSION 3.4.1)
set(NDK_SRCS ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)
add_library(app-glue STATIC  ${NDK_SRCS})
add_library(native-lib
            SHARED
           src/main/cpp/event_loop.cpp
           src/main/cpp/main.cpp
           src/main/cpp/input_event.cpp
           src/main/cpp/handle_command.cpp
           src/main/cpp/native_egl.cpp
                              )

target_include_directories(native-lib PRIVATE
                           ${ANDROID_NDK}/sources/android/native_app_glue)
target_link_libraries(native-lib
                    log
                    android
                    atomic
                    app-glue
                    EGL
                    GLESv1_CM
                    GLESv2
                   )
