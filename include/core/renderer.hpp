// Ad Maiorem Dei Gloriam!
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>
#include <algorithm>

#include <GL/glew.h>

#include "core/transform.hpp"
#include "core/shader.hpp"
#include "core/camera.hpp"
#include "core/mesh.hpp"

struct DrawCommand final
{
    Shader *shader;
    Mesh *mesh;
    TransformComponent *transform;
};

class Renderer final
{
public:
    Renderer(Camera& camera)
        : mCurrentCamera(camera) {};

    void clear() const;
    void draw(const DrawCommand command);
    void drawAll();

    void setCurrentCamera(Camera& camera) { mCurrentCamera = camera; }

private:
    std::vector<DrawCommand> mDrawCommands;
    Camera& mCurrentCamera;

    void sortDrawCommands();
};

#endif