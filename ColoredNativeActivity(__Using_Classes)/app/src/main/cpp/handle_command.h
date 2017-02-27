//
// Created by kunjeshvirani on 27/2/17.
//

#ifndef BLANKNATIVEACTIVITY_NEW_HANDLE_COMMAND_H
#define BLANKNATIVEACTIVITY_NEW_HANDLE_COMMAND_H

#include <android_native_app_glue.h>
#include "native_egl.h"
class handle_command {

public:
    static void processCommand(struct android_app* app, int32_t command);

private:
    int32_t command;


};


#endif //BLANKNATIVEACTIVITY_NEW_HANDLE_COMMAND_H
