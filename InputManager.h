//
// Created by tk on 3/30/20.
//

#ifndef OPENGL_INPUTMANAGER_H
#define OPENGL_INPUTMANAGER_H
#include "graphics_headers.h"

class InputManager
{
    private:
        inline static InputManager *instance;
        inline static bool keys[1024];

        InputManager() {};

    public:

    static InputManager* getInstance()
    {
        if(instance == NULL)
        {
            instance = new InputManager();
        }

        return instance;
    }

    static void key_callback(GLFWwindow*, int, int, int, int);
    static bool isPressed(int);
};


#endif //OPENGL_INPUTMANAGER_H
