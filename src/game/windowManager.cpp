// Ad Maiorem Dei Gloriam!
#include "game/windowManager.hpp"

WindowManager::WindowManager(const int mainWindowWidth, const int mainWindowHeight, const char *mainWindowTitle) 
{
    if (glfwInit() != GLFW_TRUE)
    {
        std::cerr << "Fatal error: could not initialise GLFW.\n";
        std::exit(1);
    }

    createWindow(mainWindowWidth, mainWindowHeight, mainWindowTitle);

    GLenum error = glewInit();
    if (error != GLEW_OK)
    {
        std::cerr << "Fatal error: could not initialise GLEW.\n" << glewGetErrorString(error) << std::endl;
        glfwTerminate();
        std::exit(1);
    }
}

WindowManager::~WindowManager() 
{
    closeAllWindows();
    glfwTerminate();
}

bool WindowManager::createWindow(int width, int height, const char *title) 
{
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        const char *errorBuffer;
        glfwGetError(&errorBuffer);
        std::cerr << "Error: Could not initialize window.\n";
        std::cerr << errorBuffer << std::endl;
        return false;
    }
    mWindows.push_back(window);
    glfwMakeContextCurrent(mWindows.back());

    return true;
}

void WindowManager::closeAllWindows() 
{
    for (auto window : mWindows)
    {
        glfwDestroyWindow(window);
    }
    mWindows.clear();
    mIsRunning = false;
}

void WindowManager::update() 
{
    for (auto window : mWindows)
    {
        if (glfwWindowShouldClose(window)) closeAllWindows();
    }
    glfwPollEvents();
}

void WindowManager::setCurrentWindow(int windowIndex)
{
    if (windowIndex < 0 || windowIndex >= mWindows.size()) return;
    mCurrentWindowIndex = windowIndex;
    glfwMakeContextCurrent(mWindows[mCurrentWindowIndex]);
}

void WindowManager::closeCurrentWindow() 
{
    closeWindow(mCurrentWindowIndex);
}

void WindowManager::closeWindow(int windowIndex)
{
    if (windowIndex < 0 || windowIndex >= mWindows.size()) return;
    glfwDestroyWindow(mWindows[windowIndex]);
    mWindows.erase(mWindows.begin() + windowIndex);
}

void WindowManager::swapAllWindows() 
{
    for (auto window : mWindows)
    {
        glfwSwapBuffers(window);
    }
}

bool WindowManager::isKeyPressed(int key)
{
    return glfwGetKey(mWindows[mCurrentWindowIndex], key);
}