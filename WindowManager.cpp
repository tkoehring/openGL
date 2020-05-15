//
// Created by tk on 3/30/20.
//

#include "WindowManager.h"

WindowManager::WindowManager(int width, int height, const char *title)
{
    window = new Window(width, height, title);
    //setKeyCallback(input->key_callback);
    setFrameBufferCallback(framebuffer_size_callback);
    makeContextCurrent();
}

void WindowManager::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void WindowManager::setFrameBufferCallback(GLFWframebuffersizefun func)
{
    glfwSetFramebufferSizeCallback(window->getHandle(), func);
}

void WindowManager::setKeyCallback(GLFWkeyfun func )
{
    glfwSetKeyCallback(window->getHandle(), func);
}

void WindowManager::makeContextCurrent()
{
    glfwMakeContextCurrent(window->getHandle());
}

void WindowManager::swapBuffers()
{
    glfwSwapBuffers(window->getHandle());
}

bool WindowManager::shouldClose()
{
    return glfwWindowShouldClose(window->getHandle());
}

void WindowManager::getWindowSize(int *w, int *h)
{
    glfwGetWindowSize(window->getHandle(), w, h);
}

void WindowManager::clear()
{
    delete window;
}

GLFWwindow * WindowManager::getWindowHandle()
{
    return window->getHandle();
}