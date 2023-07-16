//
//  Model.cpp
//  GL
//
//  Created by 王昭威 on 2023/6/25.
//

#include "Model.hpp"
#include <GLFW/glfw3.h>
#include "Shaders.hpp"
#include <iostream>

using namespace GLLearn;

Model::Model(GLfloat* vertices, GLint numOfVertices, std::vector<int>&& offsets, const GLchar* const vertShaderPath, const GLchar* const fragShaderPath, GLuint stride): _vertices(std::vector<GLfloat>(numOfVertices * 3 * offsets.size(), 0.0f)), shader(vertShaderPath, fragShaderPath){
    
    if(vertices != nullptr){
        const GLuint len = numOfVertices * 3 * offsets.size();
        for(int i = 0; i < len; ++i){
            _vertices[i] = vertices[i];
        }
        
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
        
        const GLuint program = shader.getProgram();
        shader.use();
        const GLuint matBindingPt = 0;
        GLuint matInd = glGetUniformBlockIndex(program, "Matrices");
        glUniformBlockBinding(program, matInd, matBindingPt);
    }
}

Model::Model(Model&& obj): _vertices(obj._vertices), shader("", ""){
    
}

void Model::Update(double currentTime){
    
}

void Model::render(){
    const GLfloat modelMat[] = {
        3, 0, 0, 0,
        0, 3, 0, 0,
        0, 0, 3, 11,
        0, 0, 0, 1,
    };
    shader.use();
    glBindVertexArray(VAO);
    
    shader.setUniformMatrix4fv("model", modelMat);

    glDrawArrays(GL_TRIANGLES, 0, _vertices.size() / 3);
}
