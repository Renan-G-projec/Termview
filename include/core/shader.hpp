// Ad Maiorem Dei Gloriam!
#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <string>
#include <fstream>

#include <unordered_map>

#include <glm/gtc/type_ptr.hpp>
#include <glm/mat4x4.hpp>

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

    void setUniformMatrix(const glm::mat4& matrix, const char *uniform = "u_MVP");
    GLuint getUniformLocation(const char *uniform);

private:
    GLuint mId;
    std::unordered_map<const char *, GLuint> mUniformsLocation;

};

#endif