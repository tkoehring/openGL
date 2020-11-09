//
// Created by tk on 3/31/20.
//

#ifndef OPENGL_RENDERABLE_OBJECT_H
#define OPENGL_RENDERABLE_OBJECT_H


#include "graphics_headers.h"

class Renderable_Object
{
    private:
        glm::mat4 view;
        glm::mat4 model;
        glm::mat4 projection;

    public:
        virtual void draw();
        glm::mat4 getView();
        void setView(glm::mat4);
        glm::mat4 getModel();
        void setModel(glm::mat4);
        glm::mat4 getProjection();
        void setProjection(glm::mat4);
};


#endif //OPENGL_RENDERABLE_OBJECT_H
