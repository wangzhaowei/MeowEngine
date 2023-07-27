//
//  MeshLoader.hpp
//  GL
//
//  Created by Felis Meow on 2023/7/18.
//  
//
  

#ifndef MeshLoader_hpp
#define MeshLoader_hpp

#include <stdio.h>
#include <string>
#include <memory>
#include "Mesh.hpp"
#include "../LRUCache.hpp"

namespace MeowEngine {
class Mesh;
class MeshLoader{
protected:
    static LRUCache<std::string, typename std::shared_ptr<Mesh>, 50> caches;
public:
    static std::shared_ptr<Mesh> makeMesh(float* verticesBuffer, int numOfVertices, int stride, std::vector<int>& offsets, std::string key);
    
    static std::shared_ptr<Mesh> makeMesh(std::vector<float>& verticesBuffer, int stride, std::vector<int>& offsets, std::string& key);
};
}

#endif /* MeshLoader_hpp */
