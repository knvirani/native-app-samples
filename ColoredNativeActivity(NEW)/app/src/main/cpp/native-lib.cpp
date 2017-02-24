/*
 * Created by KV on 7 February, 2017
 * On the Platform Linux (Ubuntu Xenial xerus) 64bit
 *
 * hellowwoor@gmail.com
 */

/*
 * Description
 *
 * This file contain the code of native activity with very simple and basic use of EGL and OpenGL ES libraries.
 */

#include <android_native_app_glue.h>
#include <android/log.h>
#include <EGL/egl.h>
#include <GLES/gl.h>
#define LOGW(x...) __android_log_print(ANDROID_LOG_WARN, "OnlyBlankNativeActivity",x)


struct egl {
    EGLDisplay display;
    EGLSurface surface;
    EGLContext context;
};

static void egl_init(struct android_app* app, struct egl* egl) {

    // below is the code for attributes of EGL which will be stored in configurations (config).
    const EGLint attributes[] = {
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_RED_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_NONE
    };

    // declare the several variables which will assigned to main egl struct members

    EGLint format, numConfigs;
    EGLDisplay display;
    EGLContext context;
    EGLSurface surface;
    EGLConfig config;

    // first get the EGL display connection.
    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    // after getting display connection must initialize the EGL
    eglInitialize(display, 0, 0);

    // when initialization will complete egl take a watch for choosing its configuration.
    // below function will save the choosen configuration in config and return the number of configuration in numConfig.
    eglChooseConfig(display, attributes, &config, 1, &numConfigs);

    // get the choosen configurations and set the format for native display.
    eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &format);

    // Set the geometry of native window via format returned.
    ANativeWindow_setBuffersGeometry(app->window, 0, 0, format);

    // Initialize the surface and context of EGL for render the rendering API like OpenGL ES..
    surface = eglCreateWindowSurface(display, config, app->window, 0);
    context = eglCreateContext(display, config, 0, 0);

    // make the surface and context active to the current thread which will be used in the process.
    eglMakeCurrent(display, surface, surface, context);
    egl->display = display;
    egl->surface = surface;
    egl->context = context;
}

static void engine_for_draw(struct egl* egl) {
    if(egl->display == NULL)
        return;
    glClearColor(0.34, 0.67, 0.56, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // this will post the color buffer created vua glClearColor() to native window.
    // without use of below code will output nothing except blank screen, and will not generate error.
    eglSwapBuffers(egl->display, egl->surface);
}

static void engine_terminate(struct egl* egl) {
    if(egl->display != EGL_NO_DISPLAY) {
        eglMakeCurrent(egl->display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        if(egl->surface != EGL_NO_SURFACE)
            eglDestroySurface(egl->display, egl->surface);
        if(egl->context != EGL_NO_CONTEXT)
            eglDestroyContext(egl->display, egl->context);
        eglTerminate(egl->display);
    }
    egl->display = EGL_NO_DISPLAY;
    egl->surface = EGL_NO_SURFACE;
    egl->context = EGL_NO_CONTEXT;
}

// below function for control display via various commands

static void handle_command_android(struct android_app* app, int32_t cmd) {

    struct egl* egl = (struct egl*)app->userData;

    switch (cmd) {
        case APP_CMD_INIT_WINDOW:
            egl_init(app, egl);
            engine_for_draw(egl);
            LOGW("App Window has been initiated..");
            break;
        case APP_CMD_TERM_WINDOW:
            engine_terminate(egl);
            LOGW("App Window has been terminated..");
            break;
        case APP_CMD_SAVE_STATE:
            // here sometime you have to remove the termination code from here due to large number of drawing in 1 or 2 seconds.
            // using termination code here will manage the usage of RAM when application's activity has been paused.
            engine_terminate(egl);
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

    struct egl egl;

    // memset(&egl, 0, sizeof(egl));
    int events;
    app_state->userData = &egl;
    app_state->onAppCmd = handle_command_android;
    app_state->onInputEvent = handle_input_android;


    while(1) {

        struct android_poll_source* source;

        while(ALooper_pollAll(-1, NULL, &events, (void**)&source)>=0) {
            if(source != NULL)
                source->process(app_state, source);
            if(app_state->destroyRequested != 0) {
                LOGW("We are exiting from app.");
                return;
            }
        }
    }
}

