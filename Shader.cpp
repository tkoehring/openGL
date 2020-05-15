#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const char *vsPath, const char *fsPath)
{
    unsigned int vs_id, fs_id;

    vs_id = glCreateShader(GL_VERTEX_SHADER);
    fs_id = glCreateShader(GL_FRAGMENT_SHADER);
    loadSource(vsPath, vs_id);
    loadSource(fsPath, fs_id);
    compile(vs_id, fs_id);
}

void Shader::loadSource(const char *path, int id)
{
    std::fstream shaderFile;
    std::stringstream fileStream;
    std::string fileString;
    const char *source;

    shaderFile.exceptions(std::ifstream::failbit | std::fstream::badbit);

    try
    {
        shaderFile.open(path);
        fileStream << shaderFile.rdbuf();
        fileString = fileStream.str();
        source = fileString.c_str();
        shaderFile.close();
    }
    catch(std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
    }

    glShaderSource(id, 1, &source, NULL);
}

bool Shader::compile(int vs_id, int fs_id)
{
    int success;
    char log[1024];

    compiled = true;

    glCompileShader(vs_id);
    glGetShaderiv(vs_id, GL_COMPILE_STATUS, &success);

    if(success != GL_TRUE)
    {
        glGetShaderInfoLog(vs_id, 512, NULL, log);
        std::cout << "Error Compiling Vertex Shader\n" << log << std::endl;
        compiled = false;
    }

    glCompileShader(fs_id);
    glGetShaderiv(fs_id, GL_COMPILE_STATUS, &success);

    if(success != GL_TRUE)
    {
        glGetShaderInfoLog(fs_id, 512, NULL, log);
        std::cout << "Error Compiling Fragment Shader\n" << log << std::endl;
        compiled = false;
    }

    if(compiled)
    {
        id = glCreateProgram();
        glAttachShader(id, vs_id);
        glAttachShader(id, fs_id);
        glLinkProgram(id);

        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if(success != GL_TRUE)
        {
            glGetProgramInfoLog(id, 1024, NULL, log);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << log << std::endl;
        }

        glDeleteShader(vs_id);
        glDeleteShader(fs_id);
    }
}

void Shader::activate() const
{
    if(compiled)
    {
        glUseProgram(id);
    }
    else
    {
        std::cout << "Cannot activate un-compiled Shader" << std::endl;
    }
}

void Shader::setBool(const std::string &name, bool val) const
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)val);
}

void Shader::setInt(const std::string &name, int val) const
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), val);
}

void Shader::setFloat(const std::string &name, float val) const
{
    glUniform1f(glGetUniformLocation(id, name.c_str()), val);
}

void Shader::setDouble(const std::string &name, double val) const
{
    glUniform1d(glGetUniformLocation(id, name.c_str()), val);
}

void Shader::setVec2f(const std::string& name, glm::vec2 vec) const
{
    glUniform2fv(glGetUniformLocation(id, name.c_str()), 2, glm::value_ptr(vec));
}

void Shader::setVec3f(const std::string& name, glm::vec3 vec) const
{
    glUniform3fv(glGetUniformLocation(id, name.c_str()), 3, glm::value_ptr(vec));
}

void Shader::setVec4f(const std::string& name, glm::vec4 vec) const
{
    glUniform4fv(glGetUniformLocation(id, name.c_str()), 4, glm::value_ptr(vec));
}

void Shader::setMat2f(const std::string& name, glm::mat2 mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setMat3f(const std::string& name, glm::mat3 mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::setMat4f(const std::string& name, glm::mat4 mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}