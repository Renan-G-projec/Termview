# Ad Maiorem Dei Gloriam!
cmake_minimum_required(VERSION 3.12)

project(Platview CXX)

# Fetching the contents
include(FetchContent)

set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_BUILD_WAYLAND OFF)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG master
)

set(CGLM_SHARED OFF)
set(CGLM_STATIC ON)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG master
)

FetchContent_MakeAvailable(glfw glm)

# Actual compiling
add_executable(Platview)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

target_sources(Platview PRIVATE
    src/main.cpp
    src/game/windowManager.cpp
    src/core/mesh.cpp
    src/core/vao.cpp
    src/core/vbo.cpp
    src/core/ebo.cpp
    src/core/camera.cpp
    src/core/shader.cpp
)

target_include_directories(Platview PRIVATE
    "include"
)

target_link_libraries(Platview PRIVATE glfw glm GLEW OpenGL::GL)