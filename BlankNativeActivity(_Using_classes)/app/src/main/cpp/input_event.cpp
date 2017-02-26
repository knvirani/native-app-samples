//
// Created by kunjeshvirani on 26/2/17.
//

#include "input_event.h"
#include "log.h"
int32_t input_event::android_custom_input_event(struct android_app* app, AInputEvent* event) {

    if(AInputEvent_getType(event)==AINPUT_EVENT_TYPE_MOTION)
    {
        LOG_WARN("X = %f Y = %f ",AMotionEvent_getX(event, 0), AMotionEvent_getY(event,0));
        return 1;
    }
    return 0;
}