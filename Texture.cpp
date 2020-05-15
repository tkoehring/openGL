//
// Created by tk on 3/21/20.
//

#include "Texture.h"
#include <iostream>

Texture_2d::Texture_2d(const char *file, int wrapS, int wrapT, int filterMin, int filterMag)
{
    unsigned char *data;

    glGenTextures(1, &id);
    bind();
    setTextureWrapS(wrapS);
    setTextureWrapT(wrapT);
    setTextureMinFilter(filterMin);
    setTextureMagFilter(filterMag);

    data = stbi_load(file, &width, &height, &nrChannels, 0);

    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        generateMipMap();
    }
    else
    {
        std::cout << "Failed to load texture image" << std::endl;
    }

    stbi_image_free(data);
    unbind();
}

void Texture_2d::bind()
{
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture_2d::unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture_2d::activate(int offset)
{
    glActiveTexture(GL_TEXTURE0 + offset);
}

void Texture_2d::generateMipMap()
{
    glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture_2d::setTextureWrapS(int param)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, param);
}

void Texture_2d::setTextureWrapT(int param)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, param);
}

void Texture_2d::setTextureMinFilter(int param)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, param);
}

void Texture_2d::setTextureMagFilter(int param)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, param);
}
