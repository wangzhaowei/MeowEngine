//
//  Mesh.cpp
//  GL
//
//  Created by Felis Meow on 2023/7/16.
//

#include "Mesh.hpp"
#include <OpenGL/gl3.h>


namespace MeowEngine {

Mesh::Mesh(std::vector<float>& vertices, int stride, std::vector<int>& offsets): _vertexBuffer(std::make_shared<std::vector<float>>(vertices)), _submeshes({}){
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)(offsets[0]));
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(offsets[1]));
    glEnableVertexAttribArray(1);
    //  UV
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)(offsets[2]));
    glEnableVertexAttribArray(2);
    
    glBindVertexArray(0);
};

Mesh::Mesh(Mesh&& other){
    
}
}
