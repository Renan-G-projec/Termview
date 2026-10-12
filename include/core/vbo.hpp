// Ad Maiorem Dei Gloriam!
#ifndef VBO_HPP
#define VBO_HPP

#include <vector>
#include <GL/glew.h>
#include "core/vertex.hpp"

class VBO 
{
public:
    VBO();
    ~VBO();

    void sendData(const std::vector<GLfloat>& verticesData, GLenum usage = GL_STATIC_DRAW);
    void sendData(const std::vector<Vertex>& verticesData, GLenum usage = GL_STATIC_DRAW);

    void bind() const;
    static void unbind();

private:
    GLuint mId;
};

#endif