// Ad Maiorem Dei Gloriam!
#include "core/shader.hpp"

Shader::Shader() 
{
    mId = glCreateProgram();
}

Shader::Shader(const std::string& vertexFile, const std::string& fragmentFile)
{
    mId = glCreateProgram();
    attachFile(vertexFile, GL_VERTEX_SHADER);
    attachFile(fragmentFile, GL_FRAGMENT_SHADER);
    link();
}

Shader::~Shader()
{
    glDeleteProgram(mId);
}

void Shader::attachFile(const std::string& file, GLenum type) 
{
    GLuint shader = glCreateShader(type);
    std::string src;
    std::ifstream fileStream{file};
    if (!fileStream.is_open())
    {
        std::cerr << "Error: Could not open file " << file << "while trying to attach shader in " << __FILE_NAME__ << ": " << __LINE__ << std::endl;
        return;
    }

    std::getline(fileStream, src, '\0');
    const char *srcString = src.c_str();

    glShaderSource(shader, 1, &srcString, NULL);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLsizei logSize;
        char log[512];
        glGetShaderInfoLog(shader, sizeof(log), &logSize, log);
        std::cerr << "Error while compiling shader " << file << '\n' << log << std::endl;
        return;
    }

    glAttachShader(mId, shader);
    glDeleteShader(shader);
}

void Shader::link() 
{
    glLinkProgram(mId);
    int success;
    glGetProgramiv(mId, GL_LINK_STATUS, &success);
    if (!success)
    {
        GLsizei logSize;
        char log[512];
        glGetProgramInfoLog(mId, sizeof(log), &logSize, log);
        std::cerr << "Error while linking shader\n" << log << std::endl;
        return;
    }
}

void Shader::activate() const 
{
    glUseProgram(mId);
}

void Shader::deactivate() {
    glUseProgram(0);
}

void Shader::setUniformMatrix(const glm::mat4& matrix, const char* uniform) 
{
    const GLuint location = getUniformLocation(uniform);
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

GLuint Shader::getUniformLocation(const char *uniform) 
{
    if (mUniformsLocation.find(uniform) == mUniformsLocation.end()) 
    {
        mUniformsLocation.insert({uniform, glGetUniformLocation(mId, uniform)});
    }
    return mUniformsLocation.at(uniform);
}