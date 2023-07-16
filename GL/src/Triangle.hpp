//
//  Triangle.hpp
//  GL
//
//  Created by 王昭威 on 2023/7/13.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include "Renderable.hpp"
#include "Shaders.hpp"

namespace MeowEngine {
class Triangle: public virtual Renderable{
protected:
    
    GLuint VAO;
    GLuint VBO;
    GLuint textures[2];
    MeowEngine::Shader shader;
    
public:
    Triangle() noexcept;
    
    virtual ~Triangle();
    
    virtual void render() override;
};
}

#endif /* Triangle_hpp */
