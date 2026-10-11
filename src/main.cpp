// Ad Maiorem Dei Gloriam!

#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(720, 720, "Initial setup window...", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    return 0;
}