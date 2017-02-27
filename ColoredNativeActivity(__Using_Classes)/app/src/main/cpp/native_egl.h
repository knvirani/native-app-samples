//
// Created by KV on 27 february, 2017.
// On the platform Linux (Ubuntu Xenial xerus) 64Bit
//
// hellowwoor@gmail.com
//

#ifndef BLANKNATIVEACTIVITY_NEW_NATIVE_EGL_H
#define BLANKNATIVEACTIVITY_NEW_NATIVE_EGL_H

#include <EGL/egl.h>
class native_egl {

public:
    static void egl_init(struct android_app* app, struct egl_main* eglMain);
    static void egl_draw(struct egl_main* eglMain);
    static void egl_terminate(struct egl_main* eglMain);
    struct egl_main* eglMain;


};

struct egl_main {
    EGLDisplay eglDisplay;
    EGLContext eglContext;
    EGLSurface eglSurface;
};

const EGLint attributes_egl[] = {
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_NONE

};


#endif //BLANKNATIVEACTIVITY_NEW_NATIVE_EGL_H
