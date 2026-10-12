// Ad Maiorem Dei Gloriam!
#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <glm/vec3.hpp>

struct TransformComponent
{
    glm::vec3 position{0.0f, 0.0f, 0.0f}; // Position in the world
    glm::vec3 scale{1.0f, 1.0f, 1.0f}; 
};

#endif