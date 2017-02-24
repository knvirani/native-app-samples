//
// Created by KV on 13 February, 17.
// On the platform Linux (Ubuntu Xenial Xerus) 64bit
//
// hellowwoor@gmail.com
//


/** Description
*   This file is about to definitions of customly declared functions in header "linedraw.hpp"
*   This file contains various functions that can able to draw a multiple line according to given instructions in c++.
*/

#include "linedraw.h"

// in below function do not use keyword "static" because declaration in main header will generate error due to same typw with
// two time.

 void linedraw::draw() {


    // For First Line

    glShadeModel(GL_SMOOTH); // select a flat or smooth shading
    glVertexPointer(3, GL_FLOAT, 0, lineVertices);  // define the array of vertex data.
    glColorPointer(4, GL_FLOAT, 0, lineColor);   // define the array of color.
    glEnableClientState(GL_VERTEX_ARRAY);  // enable client side capability.
    glEnableClientState(GL_COLOR_ARRAY);
    glClear(GL_COLOR_BUFFER_BIT); // clear the rendering buffers
    glDrawArrays(GL_LINES, 0, 2);
    glFlush(); // force execution of GL commands in a finite time.


    // For Second Line

    glShadeModel(GL_SMOOTH); // select a flat or smooth shading
    glVertexPointer(3, GL_FLOAT, 0, linefVertices);  // define the array of vertex data.
    glColorPointer(4, GL_FLOAT, 0, linefColor);   // define the array of color.
    glEnableClientState(GL_VERTEX_ARRAY);  // enable client side capability.
    glEnableClientState(GL_COLOR_ARRAY);
    glDrawArrays(GL_LINES, 0, 2);
    glFlush(); // force execution of GL commands in a finite time.


    // For Third Line

    glShadeModel(GL_SMOOTH); // select a flat or smooth shading
    glVertexPointer(3, GL_FLOAT, 0, linelVertices);  // define the array of vertex data.
    glColorPointer(4, GL_FLOAT, 0, linelColor);   // define the array of color.
    glEnableClientState(GL_VERTEX_ARRAY);  // enable client side capability.
    glEnableClientState(GL_COLOR_ARRAY);
    glDrawArrays(GL_LINES, 0, 2);
    glFlush(); // force execution of GL commands in a finite time.
}



