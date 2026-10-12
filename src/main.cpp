// Ad Maiorem Dei Gloriam!

#include "game/windowManager.hpp"
#include "core/shader.hpp"
#include "core/vao.hpp"
#include "core/vbo.hpp"

int main() {

    
    WindowManager wm{720, 720, "Temp title"};
    wm.createWindow(720, 389, "WIndow 2");
    Shader shader{"assets/shaders/basic.vert", "assets/shaders/basic.frag"};

    VAO vao;
    vao.bind();
    VBO vbo;
    vbo.sendData(std::vector{1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f});
    
    vao.setVertexAttribute(0, 3, 3 * sizeof(GLfloat), (void*)0);
    shader.activate();

    while (wm.isRunning()) {
        wm.update();
        wm.setCurrentWindow(0);
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        wm.setCurrentWindow(1);
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        wm.swapAllWindows();
    }
    return 0;
}