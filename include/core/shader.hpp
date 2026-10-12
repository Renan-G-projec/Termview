// Ad Maiorem Dei Gloriam!
#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <fstream>

#include <GL/glew.h>

class Shader {
public:
    Shader();
    Shader(const std::string& vertexFile, const std::string& fragmentFile);
    ~Shader();

    void activate();
    static void deactivate();

    void attachFile(const std::string& file);
    void link();
    
private:
    GLuint mId;
};

#endif