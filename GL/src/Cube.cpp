//
//  Cube.cpp
//  GL
//
//  Created by 王昭威 on 2023/7/3.
//

#include "Cube.hpp"
#include <vector>

namespace GLLearn {
std::vector<float> cube{
    //  front
    -1, -1, 1,
    0, 0, 1,
    
    1, 1, 1,
    0, 0, 1,
    
    -1, 1, 1,
    0, 0, 1,
    
    -1, -1, 1,
    0, 0, 1,
    
    1, -1, 1,
    0, 0, 1,
    
    1, 1, 1,
    0, 0, 1,

    //  top
    -1, 1, 1,
    0, 1, 0,
    
    1, 1, 1,
    0, 1, 0,
    
    -1, 1, -1,
    0, 1, 0,

    -1, 1, -1,
    0, 1, 0,
    
    1, 1, 1,
    0, 1, 0,
    
    1, 1, -1,
    0, 1, 0,


    //  back
    -1, -1, -1,
    0, 0, 1,
    
    -1, 1, -1,
    0, 0, 1,
    
    1, -1, -1,
    0, 0, 1,

    
    1, -1, -1,
    0, 0.5, 1,
    
    -1, 1, -1,
    0, 0.5, 1,
    
    1, 1, -1,
    0, 0.5, 1,

    //  bottom
    -1, -1, 1,
    0, 1, 0,
    
    -1, -1, -1,
    0, 1, 0,
    
    1, -1, 1,
    0, 1, 0,
    

    1, -1, -1,
    0, 1, 0,
    
    1, -1, 1,
    0, 1, 0,
    
    -1, -1, -1,
    0, 1, 0,
    


    //  left
    -1, -1, -1,
    1, 1, 0,
    
    -1, -1, 1,
    1, 1, 0,
    
    -1, 1, 1,
    1, 1, 0,
    

    -1, 1, 1,
    1, 1, 0,
    
    -1, 1, -1,
    1, 1, 0,
    
    -1, -1, -1,
    1, 1, 0,
    


    //  right
    1, -1, 1,
    1, 0, 0,
    
    1, -1, -1,
    1, 0, 0,
    
    1, 1, 1,
    1, 0, 0,

    1, -1, -1,
    1, 0, 0,
    
    1, 1, -1,
    1, 0, 0,
    
    1, 1, 1,
    1, 0, 0,
};
Cube::Cube(): Model(cube.data(), cube.size() / 6, std::vector<int>{0, 3}, "/Volumes/D50 SSD/Projects/GL/GL/Shaders/ShaderSources/ModelVert", "/Volumes/D50 SSD/Projects/GL/GL/Shaders/ShaderSources/ModelFrag", 6){
    
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    GLint data[256 * 256] = {};
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGB_INTEGER, GL_INT, data);
}

Cube::~Cube(){
    
}
}
