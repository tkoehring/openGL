cmake_minimum_required(VERSION 3.15)
project(openGL)

set(CMAKE_CXX_STANDARD 14)
set( CMAKE_VERBOSE_MAKEFILE on )

set(SOURCES
        main.cpp
        game.cpp
        Window.cpp
        Shader.cpp
        Texture.cpp
        Camera.cpp
        ResourceManager.cpp
        WindowManager.cpp
        InputManager.cpp
        geometry.cpp
        include/glad/glad.c
        include/stb_image/stb_image.cpp main.cpp Renderable_Object.cpp Renderable_Object.h)

add_executable(main ${SOURCES})

target_link_libraries(main glfw GL X11 Xrandr Xi dl)


