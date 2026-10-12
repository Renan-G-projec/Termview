// Ad Maiorem Dei Gloriam!
#ifndef VAO_HPP
#define VAO_HPP

#include <GL/glew.h>
class VAO 
{
public:
    VAO();
    ~VAO();

    void bind();
    static void unbind();
    
    void setVertexAttribute(int index, GLint numComponents, GLsizei stride, void* componentOffset = (void*)0);

private:
    GLuint mId;
};

#endif