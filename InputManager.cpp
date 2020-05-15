//
// Created by tk on 3/30/20.
//

#include "InputManager.h"

void InputManager::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            keys[key] = GL_TRUE;
        else if (action == GLFW_RELEASE)
            keys[key] = GL_FALSE;
    }
}

bool InputManager::isPressed(int key)
{
    return keys[key];
}