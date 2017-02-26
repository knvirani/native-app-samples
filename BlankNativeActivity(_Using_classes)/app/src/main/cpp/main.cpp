//
// Created by kunjeshvirani on 26/2/17.
//

#include "event_loop.h"
#include "input_event.h"

// below is the android_main function which is the entry point of the any native android application
// android_main() will be executed only once.

void android_main(android_app* app) {

 // in the below line we are calling a function by initializing a constructor.

 event_loop(app).run(app);
}