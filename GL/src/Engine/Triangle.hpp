//
//  Triangle.hpp
//  GL
//
//  Created by Felis Meow on 2023/7/13.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdio.h>
#include <optional>
#include "Renderable.hpp"
#include "Shaders.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"

namespace MeowEngine {
class Triangle: public virtual Renderable{
    
private:
    static std::vector<float> triVert;
    static std::vector<int> offsets;
    Mesh mesh;
    std::optional<Texture> texture;
    
protected:
    
    MeowEngine::Shader shader;
    
public:
    Triangle() noexcept;
    
    virtual ~Triangle();
    
    virtual void render() override;
};
}

#endif /* Triangle_hpp */
