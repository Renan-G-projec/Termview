// Ad Maiorem Dei Gloriam!
#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

struct Vertex
{
    Vertex(float x, float y, float z, float nx, float ny, float nz, float u, float v)
        : position{x, y, z}, normal{nx, ny, nz}, uv{u, v} {};
    Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 uv)
        : position{position}, normal{normal}, uv{uv} {};
        
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
};

#endif