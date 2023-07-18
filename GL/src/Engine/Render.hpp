//
//  Render.hpp
//  GL
//
//  Created by Felis Meow on 2023/6/25.
//

#ifndef Render_hpp
#define Render_hpp

#include <stdio.h>

namespace MeowEngine {
class Renderable;
class Render{
private:
    double _currentTime;
public:
    virtual void Update(double currentTime);
    virtual void Draw(Renderable& obj);
};
}

#endif /* Render_hpp */
