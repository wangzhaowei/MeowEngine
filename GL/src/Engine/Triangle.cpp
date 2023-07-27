//
//  Triangle.cpp
//  GL
//
//  Created by Felis Meow on 2023/7/13.
//

#include "Triangle.hpp"
#include "TextureController.hpp"
#include "MeshLoader.hpp"
#include "VerticesData.hpp"

//std::string getPath(){
//
//}"3.3.shader.vs", "3.3.shader.fs"

namespace MeowEngine {

Triangle::Triangle() noexcept:
shader("/Volumes/D50 SSD/Projects/GL/GL/Shaders/ShaderSources/VertexShader.vs", "/Volumes/D50 SSD/Projects/GL/GL/Shaders/ShaderSources/FragmentShader.fs"),
mesh(MeshLoader::makeMesh(VerticesData::_triangle.triVert, VerticesData::_triangle.stride, VerticesData::_triangle.offsets, VerticesData::_triangle.meshKey)),
texture(MeowEngine::TextureController::shared()->loadImage("/Volumes/D50 SSD/Projects/GL/GL/wall.jpeg")){
    
    if (texture.has_value()) {
        shader.use();
        
        shader.setUniform1i("diffuse", 0);
    }
}

Triangle::~Triangle(){

}

void Triangle::render(){

    if (mesh == nullptr) {
        return;
    }
    texture.value().setTexture(GL_TEXTURE0, GL_TEXTURE_2D);
    
    shader.use();
        
    GLuint func = glGetSubroutineIndex(shader.program, GL_VERTEX_SHADER, "diffuseLight2");
    GLuint subroutineLoc = glGetSubroutineUniformLocation(shader.program, GL_VERTEX_SHADER, "lightFunc2");
    if (func != GL_INVALID_INDEX && subroutineLoc != GL_INVALID_INDEX) {
        
        glUniformSubroutinesuiv(GL_VERTEX_SHADER, 1, &func);
    }
    
    glBindVertexArray(mesh->getVAO());
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
}
