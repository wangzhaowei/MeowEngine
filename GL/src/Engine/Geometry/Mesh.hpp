//
//  Mesh.hpp
//  GL
//
//  Created by Felis Meow on 2023/7/16.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include <vector>
#include "Texture.hpp"
#include <optional>
#include "MeshLoader.hpp"

namespace MeowEngine {

class Submesh;
class Model;

class Mesh{
    friend class Model;
    friend class MeshLoader;
protected:
    GLuint VAO;
    GLuint VBO;
    
    std::shared_ptr<std::vector<float>> _vertexBuffer;
    std::vector<Submesh> _submeshes;
    
public:
    GLuint getVAO(){
        return VAO;
    }
    
    std::vector<Submesh>& getSubmeshes(){
        return _submeshes;
    }
    
    Mesh(std::vector<float>& vertices, std::vector<Submesh>& submeshes): _vertexBuffer(std::make_shared<std::vector<float>>(vertices)), _submeshes(submeshes){};
    
    Mesh(std::vector<float>& vertices, int stride, std::vector<int>& offsets);
    
    Mesh(Mesh&& other);
    
    virtual ~Mesh(){
        glDeleteBuffers(1, &VBO);
        glDeleteVertexArrays(1, &VAO);
    };
};

class Submesh{
    friend class Mesh;
protected:
    
    std::optional<Texture> _texture;
    
    std::optional<std::vector<int>> _indexBuffer;
    
    std::vector<int> _offsets;
    
    int _stride;
    
public:
    Submesh(std::vector<int>& offsets, int stride): _texture(std::nullopt), _indexBuffer(std::nullopt), _offsets(offsets), _stride(stride){};
    virtual ~Submesh(){};
};

}

#endif /* Mesh_hpp */
