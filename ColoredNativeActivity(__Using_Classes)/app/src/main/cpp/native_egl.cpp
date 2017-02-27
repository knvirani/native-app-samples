//
// Created by KV on 27 february, 2017.
// On the platform Linux (Ubuntu Xenial xerus) 64Bit
//
// hellowwoor@gmail.com
//

#include "native_egl.h"
#include <android_native_app_glue.h>
#include <GLES/gl.h>
void native_egl::egl_init(struct android_app* app, struct egl_main* eglMain) {
    // these variable declaration will be used to store the value of its to public variables.
    EGLDisplay display;
    EGLContext context;
    EGLSurface surface;
    EGLConfig config;

    EGLint format, num_configs;



    // first get the currently default display connection
    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    // Immediately initialize the display connection by calling below function.
    eglInitialize(display, 0, 0);

    /*
     * After initializing the display choose the configuration for the display that will decide how display will be represented
     * infront of the android.
     */

    eglChooseConfig(display, attributes_egl, &config, 1, &num_configs);

    /* after choosing the configuration ( remember we are not defining a configuration for OpenGL Window, we are going to define
     * the configuration for the native window by using EGL which is able to run another window on its surface.
     */
    // EGL_NATIVE_VISUAL_ID is for getting the configuration for native display.
    eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &format);

    // below function will be set buffer geometry of native window.
    ANativeWindow_setBuffersGeometry(app->window, 0, 0, format);

    // create a window surface and context.
    surface = eglCreateWindowSurface(display, config, app->window, 0);
    context = eglCreateContext(display, config, 0, 0);

    // attach all data to current thread for the purpose of making it active.
    eglMakeCurrent(display, surface, surface, context);

    eglMain->eglDisplay = display;
    eglMain->eglContext = context;
    eglMain->eglSurface = surface;
}

void native_egl::egl_draw(struct egl_main* eglMain) {
    if (eglMain->eglDisplay == NULL)
        return;

    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.4, 0.7, 0.5, 1.0);

    eglSwapBuffers(eglMain->eglDisplay, eglMain->eglSurface);
}

void native_egl::egl_terminate(struct egl_main* eglMain) {
  if(eglMain->eglDisplay != EGL_NO_DISPLAY) {

      eglMakeCurrent(eglMain->eglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);

      if(eglMain->eglContext != EGL_NO_CONTEXT)
          eglDestroyContext(eglMain->eglDisplay, eglMain->eglContext);
      if(eglMain->eglSurface != EGL_NO_SURFACE)
          eglDestroySurface(eglMain->eglDisplay, eglMain->eglSurface);
      eglTerminate(eglMain->eglDisplay);

  }


    eglMain->eglContext = EGL_NO_CONTEXT;
    eglMain->eglDisplay = EGL_NO_DISPLAY;
    eglMain->eglSurface = EGL_NO_SURFACE;
}
