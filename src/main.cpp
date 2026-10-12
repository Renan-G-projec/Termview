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
    Camera cam{{0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, -1.0f}, 60.0f, 100.0f, 0.1f, 1.0f};
    Camera cam2{{0.0f, 0.0f, -1.0f}, {0.0f, 0.0f, 1.0f}, 60.0f, 100.0f, 0.1f, 1.0f};
    Renderer renderer(cam);
    Renderer renderer2(cam2);
    
    WindowManager wm{720, 720, "Temp title"};
    wm.createWindow(720, 720, "Temp title");
    wm.setCurrentWindow(0);

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
    Mesh pyramid1(pyramidVertices, pyramidIndices);

    wm.setCurrentWindow(1);
    Mesh pyramid2(pyramidVertices, pyramidIndices);
    Shader shader2{"assets/shaders/basic.vert", "assets/shaders/basic.frag"};

    TransformComponent pyramidTransform{};

    while (wm.isRunning()) { 
        wm.update();
        wm.setCurrentWindow(0);
        updateCameraInput(cam, wm);
        
        renderer.clear();
        renderer.draw({&shader, &pyramid1, &pyramidTransform});
        renderer.drawAll();

        wm.setCurrentWindow(1);
        updateCameraInput(cam2, wm);
    
        renderer2.clear();
        renderer2.draw({&shader2, &pyramid2, &pyramidTransform});
        renderer2.drawAll();

        pyramidTransform.position.z -= 0.001f;

        wm.swapAllWindows();
    }
    return 0;
}