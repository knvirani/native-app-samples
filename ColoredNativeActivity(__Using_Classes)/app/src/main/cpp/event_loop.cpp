//
// Created by kunjeshvirani on 27 february, 2017.
// On the platfrom Linux (Ubuntu Xenial xerus) 64Bit
//
// hellowwoor@gmail.com
//

#include "event_loop.h"
#include "log.h"
#include "input_event.h"
#include "handle_command.h"



/*
 * In the below data we are first initializing constructor and after that we are passing the data to the private member.
 * by doing this when a member function or variable will be called the data will be automatically initialized before the process of
 * the member function starts, this is the high importance of object oriented programming.
 *
 * Using a class type syntax or class type coding structure make a program more easy to understand and easy to debug.
 * Sometime writing all programming code in only one file make somewhat hard for understanding.
 *
 * We will follow this pattern in the all coming samples.
 *
 */


/*
 * Below data of the constructor will be first initialized and then corresponding object and functions are evaluated.
 *
 *
 */
event_loop::event_loop(android_app *app):
e_application(app),
inputEvent(inputEvent),
handleCommand(handleCommand),
nativeEgl(nativeEgl)
{
    e_application->onInputEvent = inputEvent.android_custom_input_event;
    e_application->onAppCmd = handleCommand.processCommand;
    e_application->userData = &nativeEgl.eglMain;
}




void event_loop::run(android_app* application) {

   app_dummy();

    int32_t events, result;
    struct android_poll_source* source;
    LOG_WARN("Starting a loop");
    while(1) {

        while((result = ALooper_pollAll(-1, NULL, &events, (void**)&source))>=0) {
            if(source!=NULL)
                source->process(application,source);
            if(application->destroyRequested!=0)
            {
                LOG_WARN("We are exiting");
                return;
            }
        }
    }
}






