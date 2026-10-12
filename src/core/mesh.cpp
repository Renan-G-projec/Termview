// Ad Maiorem Dei Gloriam!
#include "core/mesh.hpp" 
#include "core/log.hpp"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices)
    : mVertices(vertices), mIndices(indices)
{
    vao.bind();
    vbo.bind();
    ebo.bind();

    vbo.sendData(vertices);
    ebo.sendData(indices);

    vao.setVertexAttribute(0, 3, sizeof(Vertex)); // Position
    vao.setVertexAttribute(1, 3, sizeof(Vertex), (void*)(offsetof(Vertex, normal))); // Normal
    vao.setVertexAttribute(2, 2, sizeof(Vertex), (void*)(offsetof(Vertex, uv))); // UV
    
    vao.unbind();
    vbo.unbind();
    ebo.unbind();
}

Mesh::Mesh(const std::string& filename)
{
    LOG("Warning: tried to load a file but object loading is not supported yet.");
}

void Mesh::render()
{
    vao.bind();
    glDrawElements(GL_TRIANGLES, mIndices.size(), GL_UNSIGNED_INT, (void*)0);
}

void Mesh::lazyRender() 
{
    glDrawElements(GL_TRIANGLES, mIndices.size(), GL_UNSIGNED_INT, (void*)0);
}

void Mesh::lazyBind()
{
    vao.bind();
}