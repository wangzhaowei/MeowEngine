//
//  BatchTriangle.cpp
//  GL
//
//  Created by Felis Meow on 2023/7/27.
//  
//
  

#include "BatchTriangle.hpp"
#include "MeshLoader.hpp"
#include "VerticesData.hpp"
#include "Shaders.hpp"

namespace MeowEngine {
BatchTriangle::BatchTriangle():
BatchObject(MeshLoader::makeMesh(VerticesData::_triangle.triVert, VerticesData::_triangle.stride, VerticesData::_triangle.offsets, VerticesData::_triangle.meshKey), Shader("/Volumes/D50 SSD/Projects/GL/GL/Shaders/ShaderSources/VertexShader.vs", "/Volumes/D50 SSD/Projects/GL/GL/Shaders/ShaderSources/FragmentShader.fs")){
    
}

BatchTriangle::~BatchTriangle(){
    
}
}
