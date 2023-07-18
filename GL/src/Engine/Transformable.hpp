//
//  Transformable.hpp
//  GL
//
//  Created by Felis Meow on 2023/6/30.
//

#ifndef Transformable_hpp
#define Transformable_hpp

#include <stdio.h>
#include <vector>
#include <glm.hpp>

namespace MeowEngine{

class Transformable {
public:
    std::vector<float> translation = std::vector<float>{0, 0, 0};
    std::vector<float> scale = std::vector<float>{1, 1, 1};
    std::vector<float> rotation = std::vector<float>{0, 0, 0};
    
public:
    
    glm::mat4x4 matrix() const noexcept;
    
    void setTranslation(std::vector<float> trans){
        translation = trans;
    }
    
    virtual ~Transformable(){
        
    }
};
};



#endif /* Transformable_hpp */
