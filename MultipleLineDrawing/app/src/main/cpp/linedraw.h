//
// Created by kunjeshvirani on 13/2/17.
//
#include <GLES/gl.h>
#ifndef ASSETSLEARN_LINEDRAW_H
#define ASSETSLEARN_LINEDRAW_H


class linedraw {


public:

    static void draw();
};


// Vertices and color information for line 1.

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

// Vertices and color information for line 2.

const GLfloat linefVertices[] = {
        -0.2, -0.2, 0, // starting point of Xo, Yo, Zo
        -0.5, -0.5, 0  // end point of X1, Y1, Z1
        // minimum coord point is (-1, -1) and maximum is (1, 1) for any devices.
};

const GLfloat linefColor[] = {
        1.0f, 0.0f, 0.0f, 1.0f, // Red, Green, Blue, Aplha
        0.0f, 0.0f, 0.6f, 1.0f,
        0.0f, 0.0f, 0.0f, 1.0f
};

// Vertices and color information for line 3.


const GLfloat linelVertices[] = {
        0.1, 0.2, 0, // starting point of Xo, Yo, Zo
        -0.3, 0.5, 0  // end point of X1, Y1, Z1
        // minimum coord point is (-1, -1) and maximum is (1, 1) for any devices.
};

const GLfloat linelColor[] = {
        0.0f, 1.0f, 0.0f, 1.0f, // Red, Green, Blue, Aplha
        0.0f, 0.0f, 0.6f, 1.0f,
        0.0f, 0.0f, 0.0f, 1.0f
};






#endif //ASSETSLEARN_LINEDRAW_H
