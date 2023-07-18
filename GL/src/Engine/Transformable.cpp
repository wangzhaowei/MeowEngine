//
//  Transformable.cpp
//  GL
//
//  Created by Felis Meow on 2023/6/30.
//

#include "Transformable.hpp"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace MeowEngine {
glm::mat4x4 Transformable::matrix() const noexcept{
    glm::mat4x4 transMat = glm::mat4x4{
        1, 0, 0, translation[0],
        0, 1, 0, translation[1],
        0, 0, 1, translation[2],
        0, 0, 0, 1,
    };
    
    glm::mat4x4 scaleMat = glm::mat4x4{
        scale[0], 0, 0, 0,
        0, scale[1], 0, 0,
        0, 0, scale[2], 0,
        0, 0, 0, 1,
    };
    
    glm::mat4x4 rotateMat{
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1,
    };
    
    rotateMat = glm::rotate(rotateMat, glm::radians(rotation[0]), glm::vec3(1, 0, 0));
    rotateMat = glm::rotate(rotateMat, glm::radians(rotation[1]), glm::vec3(0, 1, 0));
    rotateMat = glm::rotate(rotateMat, glm::radians(rotation[2]), glm::vec3(0, 0, 1));
    
    return scaleMat* rotateMat * transMat;
}
}
