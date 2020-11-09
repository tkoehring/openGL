//
// Created by tk on 3/31/20.
//

#include "Renderable_Object.h"

void Renderable_Object::draw()
{

};

glm::mat4 Renderable_Object::getView()
{
    return view;
}

void Renderable_Object::setView(glm::mat4 v)
{
    view = v;
}

glm::mat4 Renderable_Object::getModel()
{
    return model;
}

void Renderable_Object::setModel(glm::mat4 m)
{
    model = m;
}

glm::mat4 Renderable_Object::getProjection()
{
    return projection;
}

void Renderable_Object::setProjection(glm::mat4 p)
{
    projection = p;
}