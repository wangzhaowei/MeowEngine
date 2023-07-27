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
    std::shared_ptr<Shader> _shader;
    
    std::optional<std::shared_ptr<Mesh>> _mesh;
    
public:
    MeowEngine::Transformable transform;
    
    Model(GLfloat* vertices, GLint numOfVertices, std::vector<int>&& offsets, const GLchar* const vertShaderPath, const GLchar* const fragShaderPath, GLuint stride = 6);
    
    Model(std::shared_ptr<Mesh> mesh, const Shader& shader);
    
    Model(Model&& obj);
    
    virtual ~Model(){};
    
    virtual void Update(double currentTime) override;
    virtual void render() override;
};

};

#endif /* Model_hpp */
