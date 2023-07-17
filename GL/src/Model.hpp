//
//  Model.hpp
//  GL
//
//  Created by Felis Meow on 2023/6/25.
//

#ifndef Model_hpp
#define Model_hpp

#include <stdio.h>
#include <vector>
#include <OpenGL/OpenGL.h>
#include "Renderable.hpp"
#include "Transformable.hpp"
#include "Texture.hpp"
#include <optional>
#include "Mesh.hpp"

namespace MeowEngine {

class Model: public virtual Renderable{
protected:
    std::vector<GLfloat> _vertices;
    GLuint verticesBuffer;

    GLuint VAO;
    Shader shader;
    
    std::optional<Mesh> mesh;
    
public:
    MeowEngine::Transformable transform;
    
    Model(GLfloat* vertices, GLint numOfVertices, std::vector<int>&& offsets, const GLchar* const vertShaderPath, const GLchar* const fragShaderPath, GLuint stride = 6);
    virtual ~Model(){};
    Model(Model&& obj);
    
    virtual void Update(double currentTime) override;
    virtual void render() override;
};

};

#endif /* Model_hpp */
