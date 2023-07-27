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

LRUCache<std::string, typename std::shared_ptr<Mesh>, 50> MeshLoader::caches;

std::shared_ptr<Mesh> MeshLoader::makeMesh(float *verticesBuffer, int numOfVertices, int stride, std::vector<int>& offsets, std::string key){
    
    auto buffer = caches.get(key);
    if (buffer.has_value()) {
        return buffer.value();
    }

    std::vector<float> vertVec(verticesBuffer, verticesBuffer + numOfVertices * stride);
    return makeMesh(vertVec, stride, offsets, key);
}

std::shared_ptr<Mesh> MeshLoader::makeMesh(std::vector<float>& verticesBuffer, int stride, std::vector<int>& offsets, std::string& key){
    auto buffer = caches.get(key);
    if (!buffer.has_value()) {
        auto meshPtr = std::make_shared<Mesh>(verticesBuffer, stride, offsets);
        caches.put(key, meshPtr);
        buffer = caches.get(key);
    }

    return buffer.value_or(nullptr);
}

}
