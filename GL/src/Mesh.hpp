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

namespace MeowEngine {

class Submesh;
class Model;

class Mesh{
    friend class Model;
protected:
    std::vector<Submesh> _submeshes;
    
public:
    std::vector<Submesh>& getSubmeshes(){
        return _submeshes;
    }
    
    Mesh(std::vector<Submesh>& submeshes): _submeshes(submeshes){};
    virtual ~Mesh(){};
};

class Submesh{
    friend class Mesh;
protected:
    std::shared_ptr<std::vector<float>> _buffer;
    
    std::optional<Texture> _texture;
    
    std::optional<std::vector<int>> _indexBuffer;
    
    std::vector<int> _offsets;
    
    int _stride;
    
public:
    Submesh(std::shared_ptr<std::vector<float>> buffer, std::vector<int>& offsets, int stride): _buffer(buffer), _texture(std::nullopt), _indexBuffer(std::nullopt), _offsets(offsets), _stride(stride){};
    virtual ~Submesh(){};
};

}

#endif /* Mesh_hpp */
