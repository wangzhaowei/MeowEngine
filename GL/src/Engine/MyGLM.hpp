//
//  MyGLM.hpp
//  GL
//
//  Created by Felis Meow on 2023/6/29.
//

#ifndef MyGLM_hpp
#define MyGLM_hpp

#include <stdio.h>
#include <vector>
#include <OpenGL/gl3.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace MeowEngine{

extern GLuint myLookAt(std::vector<float> eye, std::vector<float> center, std::vector<float> up, std::vector<float>& viewMatrix);

extern glm::vec3 vec3_2_glmvec3(std::vector<float> vec);

}


#endif /* MyGLM_hpp */
