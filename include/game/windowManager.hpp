// Ad Maiorem Dei Gloriam!
#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class WindowManager {
public:
    WindowManager();
    WindowManager(const WindowManager& other) = delete;
    ~WindowManager();

    int getWindowCount() const { return mWindows.size(); }
    void glfwSetCurrentWindow(int windowIndex);
    void createWindow(int width, int height);
    void updateAllWindows() const;
    void closeAllWindows() const;

private:
    std::vector<GLFWwindow *> mWindows;
    int mCurrentWindowIndex = 0;
};

#endif