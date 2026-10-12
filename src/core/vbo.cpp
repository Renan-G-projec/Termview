// Ad Maiorem Dei Gloriam!
#include "core/vbo.hpp"

VBO::VBO() 
{
    glGenBuffers(1, &mId);
}

VBO::~VBO() 
{
    glDeleteBuffers(1, &mId);
}

void VBO::bind() const 
{
    glBindBuffer(GL_ARRAY_BUFFER, mId);
}

void VBO::unbind() 
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::sendData(const std::vector<GLfloat>& data, GLenum usage) 
{
    bind();
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GLfloat), data.data(), usage);
}