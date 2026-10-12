// Ad Maiorem Dei Gloriam!
#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <queue>

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
    void drawAll() const;

    void setCurrentCamera(const Camera& camera);

private:
    std::queue<DrawCommand> mDrawCommands;
    Camera& mCurrentCamera;
};

#endif