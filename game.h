//
// Created by tk on 3/24/20.
//

#ifndef OPENGL_GAME_H
#define OPENGL_GAME_H

#include "graphics_headers.h"
#include "ResourceManager.h"
#include "WindowManager.h"
#include "InputManager.h"
#include "Camera.h"

enum GameState
{
    ACTIVE,
    MENU,
    QUIT,
    WINDOW
};

class game
{
    private:
        //Members
        GameState state;
        WindowManager *windowManager;
        ResourceManager *resourceManager;
        InputManager *inputManager;
        Camera *camera;

        //Methods
        void init();
        void initializeResourceManager();
        void initializeWindowManager();
        void initializeInputManager();
        void build_camera();
        void build_cubes();
        bool initializeGLFW();
        bool initializeGLAD();

    public:
        game();
        void play();
        void quit();
        void update();
        void render();
        void processInput();
};


#endif //OPENGL_GAME_H
