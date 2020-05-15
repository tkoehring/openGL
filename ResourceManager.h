//
// Created by tk on 3/24/20.
//

#ifndef OPENGL_RESOURCEMANAGER_H
#define OPENGL_RESOURCEMANAGER_H

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Shader.h"
#include "Texture.h"

class ResourceManager
{
    private:
        std::map<std::string, Shader*> shaders;
        std::map<std::string, Texture_2d*> textures;
        std::map<std::string, unsigned int> VBOs;
        std::map<std::string, unsigned int> VBAs;
        std::map<std::string, unsigned int> EBOs;

        //Methods

    public:
        ResourceManager();
        Shader* getShader(std::string);
        void loadShader(std::string, const char*, const char*);
        Texture_2d* getTexture_2d(std::string);
        void loadTexture_2d(std::string, const char*, int, int, int, int);
        void clear();
};


#endif //OPENGL_RESOURCEMANAGER_H
