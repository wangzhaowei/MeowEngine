//
//  Render.cpp
//  GL
//
//  Created by Felis Meow on 2023/6/25.
//

#include "Render.hpp"
#include "Renderable.hpp"
#include <OpenGL/OpenGL.h>
//#include <OpenGL/gl.h>
//#include <OpenGL/gl3.h>
//#include <OpenGL/gl3ext.h>

namespace MeowEngine{
void Render::Update(double currentTime){
    _currentTime = currentTime;
}

void Render::Draw(Renderable& obj){
    obj.Update(_currentTime);
    obj.render();
}
};
