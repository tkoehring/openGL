#include "graphics_headers.h"
#include "WindowManager.h"
#include "ResourceManager.h"
#include "Window.h"
#include "Shader.h"
#include "Texture.h"
#include "Camera.h"
#include "geometry.h"
#include "game.h"
#include <iostream>
#include <cmath>

bool initializeGLFW();
bool initializeGLAD();

//Camera
Camera *cam = new Camera(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));


int main(void)
{
    //Init GLFw
    initializeGLFW();

    //Initialize Managers
    WindowManager *windowManager = new WindowManager(1024, 1024, "openGL Tutorial");
    ResourceManager *resourceManager = new ResourceManager();

	//Init GLAD
	//Must happen after Window is created and context is set.
	//openGL calls only after initialization of GLAD
	initializeGLAD();

    //Set openGL draw Window to size of Window
    glViewport(0, 0, 1024, 1024);
    glEnable(GL_DEPTH_TEST);

    resourceManager->loadShader("Main Shader", "../shaders/vert.glsl", "../shaders/frag.glsl");
    //Shader *mainShader = new Shader("../shaders/vert.glsl", "../shaders/frag.glsl");

    float vertices[] = {
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
            -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    glm::vec3 cubePositions[] = {
            glm::vec3( 0.0f,  0.0f,  0.0f),
            glm::vec3( 2.0f,  5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3( 2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f,  3.0f, -7.5f),
            glm::vec3( 1.3f, -2.0f, -2.5f),
            glm::vec3( 1.5f,  2.0f, -2.5f),
            glm::vec3( 1.5f,  0.2f, -1.5f),
            glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    unsigned int VBO, VAO,  EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

	//Texture
	int width, height, nrChannels;
	unsigned int texture1, texture2;
    unsigned char *t1Data, *t2Data;
    //Texture_2d *tex1 = new Texture_2d("../assets/textures/container.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);
    //Texture_2d *tex2 = new Texture_2d("../assets/textures/wall.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);
    resourceManager->loadTexture_2d("Container", "../assets/textures/container.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);
    resourceManager->loadTexture_2d("Wall", "../assets/textures/wall.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);
    resourceManager->getShader("Main Shader")->activate();

    //Set texture1 in shader to the first texture loaded in opengl
    resourceManager->getShader("Main Shader")->setInt("texture1", 0);
    //Set texture2 in shader to the second texture loaded in opengl
    resourceManager->getShader("Main Shader")->setInt("texture2", 1);
    /*
    mainShader->activate();
    mainShader->setInt("texture1", 0);
    mainShader->setInt("texture2", 1);
    */

    //glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view;
    glm::mat4 model;
    glm::mat4 projection = glm::mat4(1.0f);

    //view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    //projection = glm::perspective(glm::radians(45.0f), (float)wWidth / (float)wHeight, 0.1f, 100.0f);

    const float radius = 10.0f;
    int w, h;
    float camX, camZ;

    std::cout << "Starting main loop" << std::endl;
	while(!(windowManager->shouldClose()))
	{
		//processInput(Window);
		//mainWindow->processInput();
        windowManager->processInput();
		//Clear Screen to Grey Color
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Activate and bind textures
        resourceManager->getTexture_2d("Container")->activate(0);
        resourceManager->getTexture_2d("Container")->bind();
        resourceManager->getTexture_2d("Wall")->activate(1);
        resourceManager->getTexture_2d("Wall")->bind();
        /*
        tex1->activate(0);
        tex1->bind();
        tex2->activate(1);
        tex2->bind();
        */
        camX = sin(glfwGetTime()) * radius;
        camZ = cos(glfwGetTime()) * radius;
        cam->setPos(glm::vec3(camX, 0.0f, camZ));
        view = cam->getView();

        //glfwGetWindowSize(mainWindow->getHandle(), &w, &h);
        windowManager->getWindowSize(&w, &h);
        projection = glm::perspective(glm::radians(45.0f), (float)w / (float)h, 0.1f, 100.0f);
        //model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(1.0f, 1.0f, 0.0f));

		//Enable Shader Program
        resourceManager->getShader("Main Shader")->activate();
        //mainShader->setMat4f("model", model);
        resourceManager->getShader("Main Shader")->setMat4f("view", view);
        resourceManager->getShader("Main Shader")->setMat4f("projection", projection);

		//Draw Square
        glBindVertexArray(VAO);
        for(unsigned int i = 0; i < 10; i++)
        {
            float angle = 20.0f * i;

            model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            resourceManager->getShader("Main Shader")->setMat4f("model", model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        //Swap Buffers and poll IO events
        windowManager->swapBuffers();
		//glfwSwapBuffers(Window);
		glfwPollEvents();
	}

	resourceManager->clear();
	windowManager->clear();
	return 0;
}

bool initializeGLFW()
{
	if(!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	return true;
}

bool initializeGLAD()
{
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}

	return true;
}

