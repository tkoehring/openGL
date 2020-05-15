//
// Created by tk on 3/30/20.
//

#ifndef OPENGL_WINDOWMANAGER_H
#define OPENGL_WINDOWMANAGER_H

#include <map>
#include <string>
#include <iostream>

#include "Window.h"
#include "InputManager.h"

class WindowManager
{
    private:
        Window *window;

        static void framebuffer_size_callback(GLFWwindow*, int, int);

    public:
        WindowManager(int, int, const char*);
        void setFrameBufferCallback(GLFWframebuffersizefun);
        void setKeyCallback(GLFWkeyfun);
        void makeContextCurrent();
        void swapBuffers();
        bool shouldClose();
        void getWindowSize(int *w, int *h);
        void clear();
        GLFWwindow* getWindowHandle();
};


#endif //OPENGL_WINDOWMANAGER_H
