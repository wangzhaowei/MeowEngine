//
//  Triangle.cpp
//  GL
//
//  Created by Felis Meow on 2023/7/13.
//

#include "Triangle.hpp"
#include "TextureController.hpp"

//std::string getPath(){
//
//}"3.3.shader.vs", "3.3.shader.fs"

namespace MeowEngine {

float vertices[] = {
    // positions         // colors              //  UV
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  1, 0,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  0, 0,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.5, 1,    // top
};

std::vector<float> Triangle::triVert{
    // positions         // colors              //  UV
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  1, 0,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  0, 0,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.5, 1,    // top
};

std::vector<int> Triangle::offsets{
    0,
    3 * sizeof(float),
    6 * sizeof(float),
};

Triangle::Triangle() noexcept:
shader("/Volumes/D50 SSD/Projects/GL/GL/Shaders/ShaderSources/VertexShader.vs", "/Volumes/D50 SSD/Projects/GL/GL/Shaders/ShaderSources/FragmentShader.fs"),
mesh(Triangle::triVert, 8 * sizeof(float), Triangle::offsets),
texture(MeowEngine::TextureController::shared()->loadImage("/Volumes/D50 SSD/Projects/GL/GL/wall.jpeg")){
    
    if (texture.has_value()) {
        shader.use();
        
        glUniform1i(glGetUniformLocation(shader.program, "diffuse"), 0);
//        glUniform1i(glGetUniformLocation(shader.program, "diffuse2"), 1);
    }
}

Triangle::~Triangle(){

}

void Triangle::render(){

    texture.value().setTexture(GL_TEXTURE0, GL_TEXTURE_2D);
    
    shader.use();
    
    glBindVertexArray(mesh.getVAO());
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
}
