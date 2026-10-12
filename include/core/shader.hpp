// Ad Maiorem Dei Gloriam!
#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <string>
#include <fstream>

#include <GL/glew.h>

class Shader 
{
public:
    Shader();
    Shader(const std::string& vertexFile, const std::string& fragmentFile);
    ~Shader();

    void activate() const;
    static void deactivate();

    void attachFile(const std::string& file, GLenum type);
    void link();

private:
    GLuint mId;
};

#endif