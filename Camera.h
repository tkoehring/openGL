//
// Created by tk on 3/21/20.
//

#ifndef OPENGL_CAMERA_H
#define OPENGL_CAMERA_H
#include "graphics_headers.h"

class Camera
{
    private:
        glm::vec3 pos;
        glm::vec3 target;
        glm::vec3 up;

    public:
        Camera(glm::vec3, glm::vec3, glm::vec3);
        glm::vec3 getPos() { return pos; };
        glm::vec3 getTarget() { return target; };
        glm::vec3 zAxis();
        glm::vec3 xAxis();
        glm::vec3 yAxis();
        void setPos(glm::vec3);
        void move(glm::vec3);
        void rotate(glm::vec3);
        glm::mat4 getView();


};


#endif //OPENGL_CAMERA_H
