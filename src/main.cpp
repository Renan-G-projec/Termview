// Ad Maiorem Dei Gloriam!

#include "game/windowManager.hpp"
#include "core/renderer.hpp"
#include "core/camera.hpp"
#include "core/shader.hpp"
#include "core/mesh.hpp"
#include "core/vao.hpp"
#include "core/vbo.hpp"
#include "core/ebo.hpp"
#include "core/log.hpp"

// Debug purpuses only XD
static void updateCameraInput(Camera& camera, WindowManager& wm)
{
    if (wm.isKeyPressed(GLFW_KEY_S)) camera.position.z += 0.5f;
    if (wm.isKeyPressed(GLFW_KEY_W)) camera.position.z -= 0.5f;
    if (wm.isKeyPressed(GLFW_KEY_D)) camera.position.x += 0.5f;
    if (wm.isKeyPressed(GLFW_KEY_A)) camera.position.x -= 0.5f;
};

int main() 
{
    Camera cam{{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, -1.0f}, 60.0f, 100.0f, 0.1f, 1.0f};
    Renderer renderer(cam);
    
    WindowManager wm{720, 720, "Temp title"};
    Shader shader{"assets/shaders/basic.vert", "assets/shaders/basic.frag"};

    const std::vector<Vertex> pyramidVertices = {
        {0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
        {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
        {0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
    };
    const std::vector<GLuint> pyramidIndices = {
        0, 1, 2,
        0, 2, 3,
        1, 2, 3,
        0, 1, 3
    };

    shader.activate();
    Mesh pyramid(pyramidVertices, pyramidIndices);

    TransformComponent pyramidTransform{};

    while (wm.isRunning()) { 
        wm.update();
        updateCameraInput(cam, wm);
        
        renderer.clear();
        renderer.draw({&shader, &pyramid, &pyramidTransform});
        renderer.drawAll();

        wm.swapAllWindows();
    }
    return 0;
}