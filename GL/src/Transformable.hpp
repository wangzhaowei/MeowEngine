//
//  Transformable.hpp
//  GL
//
//  Created by 王昭威 on 2023/6/30.
//

#ifndef Transformable_hpp
#define Transformable_hpp

#include <stdio.h>
#include <vector>

namespace MeowEngine{

class Transformable {
public:
    std::vector<float> translation;
    std::vector<float> scale;
    std::vector<float> rotation;
    
public:
    
    void setTranslation(std::vector<float> trans){
        translation = trans;
    }
    
    virtual ~Transformable(){
        
    }
};
};



#endif /* Transformable_hpp */
