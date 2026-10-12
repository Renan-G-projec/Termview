// Ad Maiorem Dei Gloriam!
#ifndef EBO_HPP
#define EBO_HPP

#include <vector>
#include <GL/glew.h>

class EBO
{
public:
    EBO();
    ~EBO();

    void sendData(const std::vector<GLuint>& indicesData, GLenum usage = GL_STATIC_DRAW);

    void bind() const;
    static void unbind();

private:
    GLuint mId;
};

#endif