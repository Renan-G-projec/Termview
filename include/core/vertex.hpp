// Ad Maiorem Dei Gloriam!
#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

struct Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 uv;
};

#endif