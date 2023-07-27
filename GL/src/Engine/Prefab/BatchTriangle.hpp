//
//  BatchTriangle.hpp
//  GL
//
//  Created by Felis Meow on 2023/7/27.
//  
//
  

#ifndef BatchTriangle_hpp
#define BatchTriangle_hpp

#include <stdio.h>
#include "Triangle.hpp"
#include "BatchObject.hpp"

namespace MeowEngine {
class BatchTriangle: public BatchObject{
public:
    BatchTriangle();
    virtual ~BatchTriangle();
};
}

#endif /* BatchTriangle_hpp */
