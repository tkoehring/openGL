//
// Created by tk on 3/23/20.
//

#include "Window.h"
#include <iostream>

Window::Window(int width, int height, const char *title)
{
    handle = glfwCreateWindow(width, height, title, NULL, NULL);

    if(handle == NULL)
    {
        std::cout << "FAILED TO CREATE WINDOW" << std::endl;
        glfwTerminate();
    }
}




