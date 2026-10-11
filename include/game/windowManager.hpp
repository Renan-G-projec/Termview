// Ad Maiorem Dei Gloriam!
#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class WindowManager 
{
public:
    WindowManager(const int mainWindowWidth, const int mainWindowHeight, const char *mainWindowTitle);
    WindowManager(const WindowManager& other) = delete;
    ~WindowManager();

    int getWindowCount() const { return mWindows.size(); }
    void setCurrentWindow(int windowIndex) { mCurrentWindowIndex = windowIndex; }
    void updateCurrentWindow();
    void closeCurrentWindow();
    bool createWindow(int width, int height, const char *title);
    void closeAllWindows();

private:
    std::vector<GLFWwindow *> mWindows;
    int mCurrentWindowIndex = 0;
};

#endif