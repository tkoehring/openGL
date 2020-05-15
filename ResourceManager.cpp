//
// Created by tk on 3/24/20.
//

#include "ResourceManager.h"

ResourceManager::ResourceManager()
{

}

Shader* ResourceManager::getShader(std::string name)
{
    return shaders[name];
}

void ResourceManager::loadShader(std::string name, const char *vShaderFile, const char *fShaderFile)
{
    shaders[name] = new Shader(vShaderFile, fShaderFile);
}

Texture_2d* ResourceManager::getTexture_2d(std::string name)
{
    return textures[name];
}

void ResourceManager::loadTexture_2d(std::string name, const char *textureFile, int wrapS, int wrapT, int filterMin, int filterMag)
{
    textures[name] = new Texture_2d(textureFile, wrapS, wrapT, filterMin, filterMag);
}

void ResourceManager::clear()
{
    shaders.clear();
    textures.clear();
}