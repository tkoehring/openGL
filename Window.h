//
// Created by tk on 3/23/20.
//

#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H
#include "graphics_headers.h"

class Window
{
    private:
        GLFWwindow* handle;

    public:
        Window(int, int, const char*);
        GLFWwindow* getHandle() { return handle; };
};


#endif //OPENGL_WINDOW_H
