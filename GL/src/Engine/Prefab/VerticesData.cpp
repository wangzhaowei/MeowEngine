//
//  VerticesData.cpp
//  GL
//
//  Created by Felis Meow on 2023/7/27.
//  
//
  

#include "VerticesData.hpp"

namespace MeowEngine {

VerticesData::Triangle VerticesData::_triangle{
    .triVert = {
        // positions         // colors              //  UV
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  1, 0,   // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  0, 0,   // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.5, 1,    // top
    },
    .offsets = {
        0,
        3 * sizeof(float),
        6 * sizeof(float),
    },
    .stride = 8 * sizeof(float),
    .meshKey = "tri",
};

}
