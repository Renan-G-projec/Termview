// Ad Maiorem Dei Gloriam!

#include "game/windowManager.hpp"
#include "core/camera.hpp"
#include "core/shader.hpp"
#include "core/vao.hpp"
#include "core/vbo.hpp"
#include "core/ebo.hpp"

int main() 
{
    Camera cam{{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, 60.0f, 100.0f, 0.1f, 1.0f};
    
    WindowManager wm{720, 720, "Temp title"};
    wm.createWindow(720, 389, "WIndow 2");
    Shader shader{"assets/shaders/basic.vert", "assets/shaders/basic.frag"};

    VAO vao;
    vao.bind();
    VBO vbo;
    vbo.sendData({1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f});
    EBO ebo;
    ebo.sendData({0, 1, 2, 1, 2, 3});

    vao.setVertexAttribute(0, 3, 3 * sizeof(GLfloat), (void*)0);
    shader.activate();

    while (wm.isRunning()) {
        cam.position.z -= 0.01f;

        
        wm.update();
        wm.setCurrentWindow(0);
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        wm.setCurrentWindow(1);
        glm::mat4 u_MVP = cam.getMatrix();
        shader.setUniformMatrix(u_MVP);
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        wm.swapAllWindows();
    }
    return 0;
}