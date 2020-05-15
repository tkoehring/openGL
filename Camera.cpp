//
// Created by tk on 3/21/20.
//

#include "Camera.h"

Camera::Camera(glm::vec3 p, glm::vec3 t, glm::vec3 u)
{
    pos = p;
    target = t;
    up = u;
}

glm::vec3 Camera::zAxis()
{
    return glm::normalize(pos - target);
}

glm::vec3 Camera::xAxis()
{
    glm::normalize(glm::cross(up, zAxis()));
}

glm::vec3 Camera::yAxis()
{
    glm::cross(zAxis(), xAxis());
}

void Camera::setPos(glm::vec3 p)
{
    pos = p;
}

glm::mat4 Camera::getView()
{
    return glm::lookAt(pos, target, up);
}