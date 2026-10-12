// Ad Maiorem Dei Gloriam!
#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <string>
#include <GL/glew.h>

#include "core/vertex.hpp"
#include "core/vbo.hpp"
#include "core/ebo.hpp"
#include "core/vao.hpp"


class Mesh
{
public:
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices); // For now its not needed to store the vertices on ram as these will not change so it should be only on vram
    Mesh(const std::string& file);

    void render();

private:
    VBO vbo;
    EBO ebo;
    VAO vao;
};

#endif