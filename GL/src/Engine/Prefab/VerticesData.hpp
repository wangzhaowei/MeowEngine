//
//  VerticesData.hpp
//  GL
//
//  Created by Felis Meow on 2023/7/27.
//  
//
  

#ifndef VerticesData_hpp
#define VerticesData_hpp

#include <stdio.h>
#include <vector>
#include <string>

namespace MeowEngine {
class VerticesData{
public:
    static struct Triangle{
        std::vector<float> triVert;
        std::vector<int> offsets;
        int stride;
        std::string meshKey;
    }_triangle;

};
}

#endif /* VerticesData_hpp */
