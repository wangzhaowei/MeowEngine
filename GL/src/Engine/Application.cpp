//
//  Application.cpp
//  GL
//
//  Created by Felis Meow on 2023/6/22.
//

#include "Application.hpp"
#include <GLFW/glfw3.h>

namespace MeowEngine {

std::map<GLFWwindow*, Application*> Application::windowMap;

void Application::WindowSizeDidChangeHandler(GLFWwindow* window, int width, int height){
    if(windowMap.find(window) != windowMap.end()){
        auto& app = *windowMap[window];
        app.WindowSizeDidChange(window, width, height);
    }
}

void Application::WindowSizeDidChange(GLFWwindow *window, int width, int height) noexcept{
    
}

void Application::Update(double currentTime){
    
}

int Application::Init(std::shared_ptr<Render> renderer){
    /* Initialize the library */
    if ( !glfwInit() )
    {
        return -1;
    }
    
    this->renderer = renderer;
    
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
     
#ifdef __APPLE__
    /* We need to explicitly ask for a 3.2 context on OS X */
    
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow( 1280, 720, "Hello World", NULL, NULL );
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    windowMap[window] = this;
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, WindowSizeDidChangeHandler);
    
    return 0;
}

int Application::Run(){
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        double time = glfwGetTime();
        Update(time);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
    
    return 0;
}

void Application::Terminate(){
    glfwTerminate();
    windowMap.erase(window);
}
}
