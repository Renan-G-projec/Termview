// Ad Maiorem Dei Gloriam!

#include "game/windowManager.hpp"
#include "core/shader.hpp"
#include "core/vbo.hpp"

int main() {

    
    WindowManager wm{720, 720, "Temp title"};
    wm.createWindow(720, 389, "WIndow 2");
    Shader shader{"assets/shaders/basic.vert", "assets/shaders/basic.frag"};

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    VBO vbo;
    vbo.sendData(std::vector{1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f});
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
    glEnableVertexAttribArray(0);
    shader.activate();

    while (wm.isRunning()) {
        wm.update();
        wm.setCurrentWindow(0);
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        wm.setCurrentWindow(1);
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        wm.swapAllWindows();
    }
    return 0;
}