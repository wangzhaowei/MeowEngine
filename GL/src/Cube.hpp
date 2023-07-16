//
//  Cube.hpp
//  GL
//
//  Created by 王昭威 on 2023/7/3.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>
#include "Model.hpp"

namespace MeowEngine {
class Cube:  virtual public Model{
    
protected:
    GLuint texture;
    
    
public:
    Cube();
    virtual ~Cube();
    
//    void Update(double currentTime) override;
//    void render(GLuint program) override;
};
}

#endif /* Cube_hpp */
