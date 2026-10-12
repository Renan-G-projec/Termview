// Ad Maiorem Dei Gloriam!

#include "game/windowManager.hpp"
#include "core/shader.hpp"

int main() {

    
    WindowManager wm{720, 720, "Temp title"};
    wm.createWindow(720, 389, "WIndow 2");
    Shader shader{"assets/shaders/basic.vert", "assets/shaders/basic.frag"};
    while (wm.isRunning()) {
        wm.update();
        wm.setCurrentWindow(0);
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        wm.setCurrentWindow(1);
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        wm.swapAllWindows();
    }
    return 0;
}