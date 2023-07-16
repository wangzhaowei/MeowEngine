//
//  Camera.hpp
//  GL
//
//  Created by 王昭威 on 2023/6/30.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include "Transformable.hpp"
#include "Shaders.hpp"

using STDVecf = std::vector<float>;

namespace MeowEngine {
class Camera{
    MeowEngine::Shader* shader = nullptr;
    GLuint ubo = 0;
public:
    GLfloat aspect = 1;//w/h
    Transformable transform;
    virtual void update();
    virtual STDVecf lookAt(STDVecf center, STDVecf up) const noexcept;
    virtual STDVecf perspective(float fov, float aspect, float near, float far) const noexcept;
    
    void init();
    
    virtual ~Camera(){
        delete shader;
        shader = nullptr;
    }
};
}

#endif /* Camera_hpp */
