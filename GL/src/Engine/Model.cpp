//
//  Model.cpp
//  GL
//
//  Created by Felis Meow on 2023/6/25.
//

#include "Model.hpp"
#include <GLFW/glfw3.h>
#include "Shaders.hpp"
#include <iostream>
#include "Mesh.hpp"
#include <gtc/type_ptr.hpp>

using namespace MeowEngine;

Model::Model(
             GLfloat* vertices,
             GLint numOfVertices,
             std::vector<int>&& offsets,
             const GLchar* const vertShaderPath,
             const GLchar* const fragShaderPath,
             GLuint stride
             ): _vertices(std::vector<GLfloat>(numOfVertices * 3 * offsets.size(), 0.0f)), _shader(std::make_shared<Shader>(vertShaderPath, fragShaderPath)), _mesh(std::nullopt){
    
    if(vertices != nullptr){
        const GLuint len = numOfVertices * 3 * offsets.size();
        for(int i = 0; i < len; ++i){
            _vertices[i] = vertices[i];
        }
        
//        std::vector<std::vector<int>> vec(std::vector<int>, 10);
        
        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);
        
        GLuint buffer;
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * len, vertices, GL_STATIC_DRAW);
        verticesBuffer = buffer;
        
        //  vert, normal, color
        std::vector<GLuint> vertAttribeteIndex{0, 1, 2};

        for (int i = 0; i < offsets.size() && i < vertAttribeteIndex.size(); i++) {
            glVertexAttribPointer(vertAttribeteIndex[i], 3, GL_FLOAT, GL_FALSE, sizeof(float) * stride, (const GLvoid*)(offsets[i] * sizeof(float)));
            glEnableVertexAttribArray(vertAttribeteIndex[i]);
        }
        
        const GLuint program = _shader->getProgram();
        _shader->use();
        const GLuint matBindingPt = 0;
        GLuint matInd = glGetUniformBlockIndex(program, "Matrices");
        glUniformBlockBinding(program, matInd, matBindingPt);
    }
}

Model::Model(std::shared_ptr<Mesh> mesh, const Shader& shader): _mesh({mesh}), _shader(std::make_shared<Shader>(shader)){
    
    
}

Model::Model(Model&& obj): _vertices(obj._vertices), _shader(nullptr){
    
}

void Model::Update(double currentTime){
    
}

void Model::render(){
    transform.translation[2] = 11;
    transform.rotation[0] = 45;
    transform.scale = {3, 3, 3};
    const glm::mat4x4 mat = transform.matrix();
    const float *pSource = (const float*)glm::value_ptr(mat);
    _shader->use();
    glBindVertexArray(VAO);
    
    _shader->setUniformMatrix4fv("model", pSource);

    glDrawArrays(GL_TRIANGLES, 0, _vertices.size() / 3);
}
