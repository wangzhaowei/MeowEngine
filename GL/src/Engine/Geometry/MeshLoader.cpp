//
//  MeshLoader.cpp
//  GL
//
//  Created by Felis Meow on 2023/7/18.
//  
//
  

#include "MeshLoader.hpp"
#include "Mesh.hpp"

namespace MeowEngine {

LRUCache<std::string, typename std::shared_ptr<std::vector<float>>, 50> MeshLoader::caches;

std::shared_ptr<Mesh> MeshLoader::makeMesh(float *verticesBuffer, int numOfVertices, int stride){
    
//    auto verPtr = new std::vector<float>();
//    verPtr->assign(verticesBuffer, verticesBuffer + numOfVertices * stride);
//    auto ptr = std::make_shared<Mesh>(verPtr, stride);
    
    return nullptr;
}

}
