//
// Created by tk on 3/24/20.
//

#include "game.h"
#include <iostream>

game::game()
{
    init();
}

void game::init()
{
    state = ACTIVE;
    initializeGLFW();
    initializeResourceManager();
    initializeWindowManager();
    initializeInputManager();
    initializeGLAD();
    build_camera();
}

void game::initializeResourceManager()
{
    resourceManager = new ResourceManager();
}

void game::initializeWindowManager()
{
    windowManager = new WindowManager(1024, 1024, "openGL Tutorial");
    windowManager->setKeyCallback(inputManager->key_callback);
}

void game::initializeInputManager()
{
    inputManager = InputManager::getInstance();
}

void game::build_camera()
{
    camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}

bool game::initializeGLFW()
{
    if(!glfwInit())
    {
        std::cout << "FAILED TO INITIALIZE GLFW" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return true;
}

bool game::initializeGLAD()
{
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "FAILED TO INITIALIZE GLAD" << std::endl;
        return false;
    }

    return true;
}

void game::play()
{
    while(state != QUIT)
    {
        glfwPollEvents();
        processInput();
        update();
        render();
    }

    quit();
}

void game::quit()
{
    glfwSetWindowShouldClose(windowManager->getWindowHandle(), true);
}

void game::update()
{

}

void game::render()
{

}

void game::processInput()
{
    if(inputManager->isPressed(GLFW_KEY_ESCAPE))
    {
        state = QUIT;
    }

    if(inputManager->isPressed(GLFW_KEY_1) == GLFW_PRESS)
    {
        //Fill Mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    if(inputManager->isPressed(GLFW_KEY_2) == GLFW_PRESS)
    {
        //Wifeframe Mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    if(inputManager->isPressed(GLFW_KEY_3) == GLFW_PRESS)
    {
        //Vertex Mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    }

    if(inputManager->isPressed( GLFW_KEY_W) == GLFW_PRESS)
    {

    }
}
