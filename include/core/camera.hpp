// Ad Maiorem Dei Gloriam!
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Camera
{
    Camera(glm::vec3 position, glm::vec3 orientation, float fov = 60.0f, float far = 100.0f, float near = 0.01f, float viewRatio = 1280.0f / 720.0f)
        : position{position}, orientation{orientation}, fov{glm::radians(fov)}, far{far}, near{near}, viewRatio{viewRatio} {};

    glm::vec3 position, orientation;
    float fov, far, near;
    float viewRatio;

    glm::mat4 getMatrix();
};

#endif