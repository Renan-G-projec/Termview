// Ad Maiorem Dei Gloriam!

#include "game/windowManager.hpp"
#include "core/camera.hpp"
#include "core/shader.hpp"
#include "core/mesh.hpp"
#include "core/vao.hpp"
#include "core/vbo.hpp"
#include "core/ebo.hpp"
#include "core/log.hpp"

int main() 
{
    Camera cam{{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, 60.0f, 100.0f, 0.1f, 1.0f};
    
    WindowManager wm{720, 720, "Temp title"};
    wm.createWindow(720, 389, "WIndow 2");
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


    while (wm.isRunning()) { 
        cam.position.z -= 0.1f;       
        wm.update();
        wm.setCurrentWindow(0);
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        wm.setCurrentWindow(1);
        glm::mat4 u_MVP = cam.getMatrix();
        shader.setUniformMatrix(u_MVP);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        pyramid.render();

        wm.swapAllWindows();
    }
    return 0;
}