//
//  Renderable.hpp
//  GL
//
//  Created by 王昭威 on 2023/6/25.
//

#ifndef Renderable_hpp
#define Renderable_hpp

#include <stdio.h>
#include "Shaders.hpp"

namespace MeowEngine {
class Renderable{
public:
    virtual void Update(double currentTime);
    virtual void render();
};
}

#endif /* Renderable_hpp */
