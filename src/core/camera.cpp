// Ad Maiorem Dei Gloriam!
#include "core/camera.hpp"

glm::mat4 Camera::getMatrix()
{
    glm::mat4 view{1.0f}, projection{1.0f};
    view = glm::lookAt(position, position + orientation, {0.0f, 1.0f, 0.0f});
    projection = glm::perspective(fov, viewRatio, near, far);
    return projection * view;
}