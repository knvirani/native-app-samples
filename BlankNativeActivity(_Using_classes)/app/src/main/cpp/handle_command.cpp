//
// Created by KV on 26 february, 2017.
// On the platform Linux (Ubuntu Xenial xerus) 64Bit
//
// hellowwoor@gmail.com
//

#include "handle_command.h"
#include "log.h"

/*
 * below function is comes fro "handle_command" class so it will be declared like below:
 * declaration steps:
 * step1: type a the data-type of function first.
 * step2: write a class name in which a purticular function is belongs.
 * step3: wirte a function name for define it.
 */







void handle_command::processCommand(struct android_app* app, int32_t command) {
    switch (command) {
        case APP_CMD_INIT_WINDOW:
            LOG_WARN("APP_CMD_INIT_WINDOW is activated");
            break;
        case APP_CMD_TERM_WINDOW:
            LOG_WARN("APP_CMD_TERM_WINDOW is activated");
            break;
        case APP_CMD_SAVE_STATE:
            LOG_WARN("APP_CMD_SAVE_STATE is activated");
            break;
        case APP_CMD_WINDOW_RESIZED:
            LOG_WARN("APP_CMD_WINDOW_RESIZED is activated");
            break;
        case APP_CMD_CONFIG_CHANGED:
            LOG_WARN("APP_CMD_CONFIG_CHANGED is activated");
            break;
        case APP_CMD_CONTENT_RECT_CHANGED:
            LOG_WARN("APP_CMD_CONTENT_RECT_CHANGED is activated");
            break;
        case APP_CMD_DESTROY:
            LOG_WARN("APP_CMD_DESTROY is activated");
            break;
        case APP_CMD_GAINED_FOCUS:
            LOG_WARN("APP_CMD_GAINED_FOCUS is activated");
            break;
        case APP_CMD_INPUT_CHANGED:
            LOG_WARN("APP_CMD_INPUT_CHANGED is activated");
            break;
        case APP_CMD_LOST_FOCUS:
            LOG_WARN("APP_CMD_LOST_FOCUS is activated");
            break;
        case APP_CMD_LOW_MEMORY:
            LOG_WARN("APP_CMD_LOW_MEMORY is activated");
            break;
        case APP_CMD_PAUSE:
            LOG_WARN("APP_CMD_PAUSE is activated");
            break;
        case APP_CMD_RESUME:
            LOG_WARN("APP_CMD_RESUME is activated");
            break;
        case APP_CMD_START:
            LOG_WARN("APP_CMD_START is activated");
            break;
        case APP_CMD_STOP:
            LOG_WARN("APP_CMD_STOP is activated");
            break;
        case APP_CMD_WINDOW_REDRAW_NEEDED:
            LOG_WARN("APP_CMD_WINDOW_REDRAW_NEEDED is activated");
            break;
        default:
            LOG_WARN("NONE OF COMMAND IS ACTIVED !");
            break;
    }
}
