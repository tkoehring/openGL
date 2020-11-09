#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "graphics_headers.h"
#include "Shader.h"
#include "Texture.h"
#include "Renderable_Object.h"
#include <vector>
#include <map>

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

class cube : public Renderable_Object
{
    private:
        glm::vec3 center;
        float *vertices;
        glm::vec3 *cubePositions;
        unsigned int VAO, VBO;
        int vertCount = 180;

        void genVerts();
        void genBuffers();
        void fillBuffers();
    public:
        cube(glm::vec3 c);
        void draw();
};
#endif