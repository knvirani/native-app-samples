//
// Created by KV on 13 february, 2017.
// On the platform Linux (Ubuntu Xenial Xerus) 64bit
//
// hellowwoor@gmail.com
//

/** Description
*   This file contains c++ code of customly defined function that is declared in the header "linedraw.hpp".
*   Functions of this file will draw a single line accordingly to given instructions in c++.
*/

#include "linedraw.h"

// in below function do not use keyword "static" because declaration in main header will generate error due to same typw with
// two time.

 void linedraw::draw() {

    glShadeModel(GL_SMOOTH); // select a flat or smooth shading
    glVertexPointer(3, GL_FLOAT, 0, lineVertices);  // define the array of vertex data.
    glColorPointer(4, GL_FLOAT, 0, lineColor);   // define the array of color.
    glEnableClientState(GL_VERTEX_ARRAY);  // enable client side capability.
    glEnableClientState(GL_COLOR_ARRAY);

    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_LINES, 0, 2);
    glFlush(); // force execution of GL commands in a finite time.

}



