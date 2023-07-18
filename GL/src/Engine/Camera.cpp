//
//  Camera.cpp
//  GL
//
//  Created by Felis Meow on 2023/6/30.
//

#include "Camera.hpp"
#include "MyGLM.hpp"
#include <math.h>
#include "ShaderSrc.hpp"

namespace MeowEngine {

void Camera::update(){
    const std::vector<float>& viewMatrix = lookAt({0, 0, 11}, {0, 1, 0});
    const std::vector<float>& projectionMat = perspective(M_PI / 180.0 * 120, aspect, 0.1, 100);
    
    const int bufLen = 16 * 2 + 4;
    float matBuffers[bufLen] = {};
    memset(matBuffers, 0, sizeof(float) * bufLen);
    float scale = 1.f;
    memcpy(matBuffers, &scale, sizeof(float));
    memcpy(matBuffers + 4, viewMatrix.data(), sizeof(float) * 16);
    memcpy(matBuffers + 20, projectionMat.data(), sizeof(float) * 16);
    
    if(ubo == 0){
        glGenBuffers(1, &ubo);
    }
    glBindBuffer(GL_UNIFORM_BUFFER, ubo);
    glBufferData(GL_UNIFORM_BUFFER, sizeof(matBuffers), matBuffers, GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void Camera::init(){
    
    shader = new MeowEngine::Shader(modelVertSrc, modelFragSrc);
    glGenBuffers(1, &ubo);
    const GLuint matBindingPt = 0;
    GLuint matInd = glGetUniformBlockIndex(shader->getProgram(), "Matrices");
    glUniformBlockBinding(shader->getProgram(), matInd, matBindingPt);

    glBindBufferBase(GL_UNIFORM_BUFFER, matBindingPt, ubo);
}

STDVecf Camera::lookAt(STDVecf &&center, STDVecf &&up) noexcept{
    return Camera::lookAt(center, up);
}

STDVecf Camera::lookAt(STDVecf& center, STDVecf& up) noexcept{
    STDVecf eye{transform.translation};
    STDVecf viewMat;
//    glm::mat4 view = glm::lookAt(vec3_2_glmvec3(eye), vec3_2_glmvec3(center), vec3_2_glmvec3(up));
    glm::mat4 view = glm::lookAtLH(vec3_2_glmvec3(eye), vec3_2_glmvec3(center), vec3_2_glmvec3(up));
//    myLookAt(eye, center, up, viewMat);
    
//    transform.translation = center;
    
    STDVecf per2 = STDVecf{
        view[0][0], view[0][1], view[0][2], view[0][3],
        view[1][0], view[1][1], view[1][2], view[1][3],
        view[2][0], view[2][1], view[2][2], view[2][3],
        view[3][0], view[3][1], view[3][2], view[3][3],
    };
    return per2;
}

STDVecf Camera::perspective(float fov, float aspect, float near, float far) const noexcept{
     
    float inverseTan = 1.0 / (tanf(fov * 0.5));
    
//    glm::mat4 mat = glm::perspective(fov, aspect, near, far);
    glm::mat4 mat = glm::perspectiveLH(fov, aspect, near, far);
//    STDVecf per = STDVecf{
//        inverseTan / aspect, 0, 0, 0,
//        0, inverseTan, 0, 0,
//        0, 0, (far + near) / (far - near), 1,
//        0, 0, -2 * far * near / (far - near), 0, 
//    };
    STDVecf per2 = STDVecf{
        mat[0][0], mat[0][1], mat[0][2], mat[0][3],
        mat[1][0], mat[1][1], mat[1][2], mat[1][3],
        mat[2][0], mat[2][1], mat[2][2], mat[2][3],
        mat[3][0], mat[3][1], mat[3][2], mat[3][3],
    };
    return per2;
    return STDVecf{
        inverseTan / aspect, 0, 0, 0,
        0, inverseTan, 0, 0,
        0, 0, -(far + near) / (far - near), -1,
        0, 0, -2 * far * near / (far - near), 0,
    };
//    return STDVecf{
//        mat[0][0], mat[0][1], mat[0][2], mat[0][3],
//        mat[1][0], mat[1][1], mat[1][2], mat[1][3],
//        mat[2][0], mat[2][1], mat[2][2], mat[2][3],
//        mat[3][0], mat[3][1], mat[3][2], mat[3][3],
//    };
}
}
