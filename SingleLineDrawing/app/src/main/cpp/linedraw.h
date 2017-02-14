//
// Created by kunjesh virani on 13/2/17.
//
#include <GLES/gl.h>
#ifndef ASSETSLEARN_LINEDRAW_H
#define ASSETSLEARN_LINEDRAW_H


class linedraw {


public:

    static void draw();
};


const GLfloat lineVertices[] = {
        0, 0, 0, // starting point of Xo, Yo, Zo
        0.5, 0.5, 0  // end point of X1, Y1, Z1
                    // minimum coord point is (-1, -1) and maximum is (1, 1) for any devices.
};

const GLfloat lineColor[] = {
        1.0f, 0.4f, 0.0f, 1.0f, // Red, Green, Blue, Aplha
        0.0f, 0.7f, 0.6f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f
};





#endif //ASSETSLEARN_LINEDRAW_H
