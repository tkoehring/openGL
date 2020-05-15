//
// Created by tk on 3/21/20.
//

#ifndef OPENGL_TEXTURE_H
#define OPENGL_TEXTURE_H

#include "graphics_headers.h"

class Texture_2d
{
    private:
        int width, height, nrChannels;
        unsigned int id;
    public:
    Texture_2d(const char*, int, int, int, int);

    void bind();
    void unbind();
    void activate(int);
    void generateMipMap();
    void setTextureWrapS(int);
    void setTextureWrapT(int);
    void setTextureMinFilter(int);
    void setTextureMagFilter(int);

};


#endif //OPENGL_TEXTURE_H
