// Ad Maiorem Dei Gloriam!
#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <string>
#include <GL/glew.h>

#include "core/transform.hpp"

#include "core/vertex.hpp"
#include "core/vbo.hpp"
#include "core/ebo.hpp"
#include "core/vao.hpp"


class Mesh
{
public:
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices);
    Mesh(const std::string& file);

    void render();
    void lazyRender();
    void lazyBind(); 

private:
    VBO vbo;
    EBO ebo;
    VAO vao;

    std::vector<Vertex> mVertices;
    std::vector<GLuint> mIndices;
};

#endif