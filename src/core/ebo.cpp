// Ad Maiorem Dei Gloriam!
#include "core/ebo.hpp"

EBO::EBO() 
{
    glGenBuffers(1, &mId);
}

EBO::~EBO() 
{
    glDeleteBuffers(1, &mId);
}

void EBO::bind() const 
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mId);
}

void EBO::unbind() 
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::sendData(const std::vector<GLuint>& data, GLenum usage) 
{
    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GLuint), data.data(), usage);
}