/*
 * Created by KV on 7 February, 2017
 * On the Platform Linux (Ubuntu Xenial xerus) 64bit
 *
 * hellowwoor@gmail.com
 */

/*
 * Description
 *
 * This file is contain code of only blank native activity which will perform output only black screen.
 * this is the simplest form of native activity.
 * you will see step by step process of application run time via logging.
 */

#include <android_native_app_glue.h>
#include <android/log.h>

#define LOGW(x...) __android_log_print(ANDROID_LOG_WARN, "OnlyBlankNativeActivity",x)


// below function for control display via various commands

static void handle_command_android(struct android_app* app, int32_t cmd) {
    switch (cmd) {
        case APP_CMD_INIT_WINDOW:
            LOGW("App Window has been initiated..");
            break;
        case APP_CMD_TERM_WINDOW:
            LOGW("App Window has been terminated..");
            break;
        case APP_CMD_SAVE_STATE:
            LOGW("App window's state has been saved.. or Window has been minimized");
            break;
        default:
            break;
    }
}
static int32_t handle_input_android(struct android_app* app, AInputEvent* event) {

    // below code is for catch handle input.

    if(AInputEvent_getType(event)==AINPUT_EVENT_TYPE_MOTION) {
        LOGW("Coordinates X = %f, Y = %f ", AMotionEvent_getX(event,0), AMotionEvent_getY(event,0));
        return 1;
    }
    return 0;
}

// below code is for android_main() which is the entry point of our execution.

void android_main(struct android_app* app_state) {

    // below code is for determine that glue is not stripped, because if it is stripped it will remove the module android_native_app_glue.o which will stop the execution. So use of app_dummy() function will embed it.
    app_dummy();

    // below variable declaration is for catch the events and process it.
    int events;
    app_state->onAppCmd = handle_command_android;
    app_state->onInputEvent = handle_input_android;


    while(1) {

        struct android_poll_source* source;

        while(ALooper_pollAll(-1, NULL, &events, (void**)&source)>=0) {
            if(source != NULL)
                source->process(app_state, source);
            if(app_state->destroyRequested != 0) {
                LOGW("We are exiting from app.");
            }
        }
    }
}

