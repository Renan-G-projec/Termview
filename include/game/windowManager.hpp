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
    void update();
    void setCurrentWindow(int windowIndex);
    void closeCurrentWindow();
    void closeWindow(int windowIndex);

    void swapAllWindows();
    bool createWindow(int width, int height, const char *title);
    void closeAllWindows();

    bool isRunning() const { return mIsRunning; }
    bool isKeyPressed(int key);
private:
    std::vector<GLFWwindow *> mWindows;
    int mCurrentWindowIndex = 0;
    bool mIsRunning = true;
};

#endif