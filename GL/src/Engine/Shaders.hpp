//
//  Shaders.hpp
//  GL
//
//  Created by Felis Meow on 2023/6/25.
//

#ifndef Shaders_hpp
#define Shaders_hpp

#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

extern GLuint modelVertShader;
extern GLuint modelFragShader;

static const GLchar* modelVertSrc[] =
    {
        "#version 410 core                             \n"
        "                                                       \n"
        "layout (location = 0) in vec3 pos; \n"
        "layout (location = 1) in vec3 normal; \n"
        "layout (location = 2) in vec3 color; \n"

        "\n"
        "uniform mat4 model;\n"
        "layout(std140) uniform Matrices{ \n"
        "   float scale;\n"
        "   mat4 view;\n"
        "   mat4 projection;\n"
        "};\n"
        "layout(std140) uniform Matrices2{ \n"
        "   float scale2;\n"
        "   mat4 view2;\n"
        "   mat4 projection2;\n"
        "};\n"
        "out vec4 vsOut;\n"
        "out vec3 fragNormal;\n"
        
        "void main(void)                               \n"
        "{                                                      \n"
        "   gl_Position = projection * view * model * vec4(pos.xyz, 1.0);\n"
        "   vsOut = vec4(0.5, 0.25, 1, 1.0);                                            \n"
        "   fragNormal = normal;                 \n"
        "}\n"
    };

static const GLchar* modelFragSrc[] =
    {
        "#version 410 core                             \n"
        "                                              \n"
        "out vec4 color;                               \n"
        "in vec4 vsOut;                       \n"
        "in vec3 fragNormal; \n "
        "uniform sampler2D tex;\n"
        "                                              \n"
        "void main(void)                               \n"
        "{                                             \n"
//                "    color = vsOut.clr;         \n"
        "   color = vec4(1, 1, 1, 1);\n"
        "   color = vec4(fragNormal.xyz, 1);\n"
//        "color = texelFetch(tex, ivec2(gl_FragCoord.xy), 0);"
        "}                                             \n"
    };

extern std::ostream& operator<< (std::ostream& out, const std::vector<char> v);

namespace MeowEngine {
class Shader{
private:
    
public:
    GLuint program;
    const char** const vert;
    const char** const frag;
    
    GLuint getProgram(){
        return program;
    }
    
    void setUniform1i(const char* name, GLuint v0){
        glUniform1i(glGetUniformLocation(program, name), v0);
    }
    
    void setUniformMatrix4fv(const std::string& name, const GLfloat modelMat[]){
        const GLint modelMatLoc = getUniformLocation(name.c_str());
        glUniformMatrix4fv(modelMatLoc, 1, GL_TRUE, modelMat);
    }
    
    GLuint getUniformLocation(const GLchar* name){
        return glGetUniformLocation(program, name);
    }
    
    Shader(const Shader& other): program(other.program), vert(other.vert), frag(other.frag){}
    
    Shader(const char** const vertPtr, const char** const fragPtr): program(0), vert(vertPtr), frag(fragPtr){
        
        program = glCreateProgram();

        GLuint vert = Shader::compile(GL_VERTEX_SHADER, vertPtr);
        GLuint frag = Shader::compile(GL_FRAGMENT_SHADER, fragPtr);
        
        glAttachShader(program, vert);
        glAttachShader(program, frag);
        
        glLinkProgram(program);
        
        // print linking errors if any
        GLint success = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if(!success)
        {
            const int maxLen = 512;
            std::vector<char> infoLog(maxLen);
            glGetProgramInfoLog(program, maxLen, NULL, &infoLog[0]);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        
        glDeleteShader(vert);
        glDeleteShader(frag);
    }
    
    Shader(const char* vertexPath, const char* fragmentPath): program(-1), vert(nullptr), frag(nullptr)
    {
        // 1. retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        // ensure ifstream objects can throw exceptions:
        vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            // open files
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;
            // read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // convert stream into string
            vertexCode   = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
        }
        const char* vShaderCode = vertexCode.c_str();
        const char * fShaderCode = fragmentCode.c_str();
        // compile shaders
        unsigned int vertex, fragment;
        // vertex shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");
        // fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");
        // shader Program
        program = glCreateProgram();
        glAttachShader(program, vertex);
        glAttachShader(program, fragment);
        glLinkProgram(program);
        checkCompileErrors(program, "PROGRAM");
        // delete the shaders as they're linked into our program now and no longer necessary
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }
    
    virtual ~Shader(){
        glDeleteProgram(program);
    }
    
    void use(){
        glUseProgram(program);
    }
    
private:
    void checkCompileErrors(GLuint shader, std::string type){
        int success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
    
protected:
    static GLuint compile(GLenum type, const GLchar* src[]){
        auto compileShader = [](GLenum type, const GLchar* src[])->GLuint{
            GLuint shader = glCreateShader(type);
            glShaderSource(shader, 1, src, NULL);
            glCompileShader(shader);
            GLint success = 0;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (success == GL_FALSE) {
                //Setup Error Log
                GLint maxLength = 0;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
                std::vector<char> errorLog(maxLength);
                glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);
                std::string log;
                for (int i = 0; i < errorLog.size(); i++) {
                    log += errorLog[i];
                }
                glDeleteShader(shader);
            }
            return shader;
        };
        
        return compileShader(type, src);
    }
};
}

#endif /* Shaders_hpp */
