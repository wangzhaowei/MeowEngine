//
//  BatchObject.cpp
//  GL
//
//  Created by Felis Meow on 2023/7/27.
//  
//
  
#include "BatchObject.hpp"
#include <gtc/type_ptr.hpp>

namespace MeowEngine {

BatchObject::BatchObject(std::shared_ptr<Mesh> mesh, const Shader& shader): Model(mesh, shader){
    
}

BatchObject::~BatchObject(){
    
}

void BatchObject::Update(double currentTime){
    
}

void BatchObject::render(){
    transform.translation[2] = 11;
    transform.rotation[0] = 45;
    transform.scale = {3, 3, 3};
    const glm::mat4x4 mat = transform.matrix();
    const float *pSource = (const float*)glm::value_ptr(mat);

    _shader->use();
    glBindVertexArray(VAO);
    
    _shader->setUniformMatrix4fv("model", pSource);

    glDrawArraysInstanced(GL_TRIANGLES, 0,  _vertices.size() / 3, 10);
}

}
