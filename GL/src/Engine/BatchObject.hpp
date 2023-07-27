//
//  BatchObject.hpp
//  GL
//
//  Created by Felis Meow on 2023/7/27.
//  
//
  

#ifndef BatchObject_hpp
#define BatchObject_hpp

#include <stdio.h>
#include <memory>
#include "Model.hpp"

namespace MeowEngine {
class BatchObject: public Model{
public:
    BatchObject(std::shared_ptr<Mesh> meshPtr, const Shader& shader);
    virtual ~BatchObject();
    
    
    virtual void Update(double currentTime) override;
    virtual void render() override;
};
}

#endif /* BatchObject_hpp */
