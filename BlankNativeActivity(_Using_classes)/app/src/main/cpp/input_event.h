//
// Created by KV on 26 february, 2017.
// On the platform Linux (Ubuntu Xenial xerus) 64Bit
//
// hellowwoor@gmail.com
//

#ifndef BLANKNATIVEACTIVITY_NEW_INPUT_EVENT_H
#define BLANKNATIVEACTIVITY_NEW_INPUT_EVENT_H

#include <android_native_app_glue.h>
#include <android/input.h>

class input_event {
public:
    static int32_t android_custom_input_event(struct android_app* app, AInputEvent* event);
    AInputEvent* event;
    struct android_app* app;

};


#endif //BLANKNATIVEACTIVITY_NEW_INPUT_EVENT_H
