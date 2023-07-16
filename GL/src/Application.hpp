//
//  Application.hpp
//  GL
//
//  Created by 王昭威 on 2023/6/22.
//

#ifndef Application_hpp
#define Application_hpp

#include <stdio.h>
#include <memory>
#include <map>

class GLFWwindow;
namespace MeowEngine {
class Renderable;
class Render;
class Application{
protected:
    static std::map<GLFWwindow*, Application*> windowMap;
    
    std::shared_ptr<Render> renderer;

public:
    GLFWwindow* window = nullptr;
    Application(){}
    
    static void WindowSizeDidChangeHandler(GLFWwindow* window, int width, int height);
    virtual void WindowSizeDidChange(GLFWwindow* window, int width, int height) noexcept;
    
    virtual int Init(std::shared_ptr<Render> renderer);
    virtual int Run();
    virtual void Terminate();
    
    virtual void Update(double currentTime);
};
}

#endif /* Application_hpp */
