// Ad Maiorem Dei Gloriam!
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

class Camera
{
public:
    Camera(glm::vec3 position, glm::vec3 orientation, float fov = 60.0f, float far, float near, float viewRatio)
        : mPosition{position}, mOrientation{orientation}, mFov{glm::radians(fov)}, mFar{far}, mNear{near}, mViewRatio{viewRatio} {};
    
    glm::mat4 getMatrix();

private:
    glm::vec3 mPosition, mOrientation;
    float mFov, mFar = 100.0f, mNear = 0.1f;
    float mViewRatio;
};

#endif