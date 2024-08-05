/* Ask for an OpenGL Core Context */
#define GLFW_INCLUDE_GLCOREARB
#include <iostream>
#include <memory>
#include "Application.hpp"
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include <math.h>
#include <memory>
#include "Renderable.hpp"
#include "Render.hpp"
#include "Model.hpp"
#include "Shaders.hpp"
#include "Camera.hpp"
#include <string.h>
#include "Cube.hpp"
#include <math.h>
#include "Triangle.hpp"

class MyApplication: virtual public MeowEngine::Application{
    
protected:
    double _time = 0;
    std::shared_ptr<MeowEngine::Model> model;
    MeowEngine::Camera camera = MeowEngine::Camera();
    
    MeowEngine::Shader* ourShader = nullptr; // you can name your shader files however you like
    
    std::vector<MeowEngine::Renderable*> objects;
    
    GLuint VBO, VAO;
        
public:
    virtual int initWindow(std::shared_ptr<MeowEngine::Render> renderer) override{
        using namespace MeowEngine;
        int ret = Application::initWindow(renderer);
        
        if (ret != 0) {
            return ret;
        }
        
        camera.init();
        
        glEnable(GL_CULL_FACE);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        
        glFrontFace(GL_CW);
        
//        glEnable(GL_DEPTH_TEST);

//        model = std::make_shared<Model>(vertices, 3, std::vector<int>{0, 3}, 6);
        model = std::make_shared<Cube>();
        objects.emplace_back(new Triangle());
                
        camera.transform.translation = {0, 0.0, -2};
        setUpMVP(1, 1);
        
        return 0;
    }
    
    virtual void Update(double currentTime) override{
        /* Render here */
        static const GLfloat red[] = { 0.0f, 0.0f, 0.f, 1.0f };
        glClearBufferfv(GL_COLOR, 0, red);

        _time = currentTime;

        int size[2];
        glfwGetWindowSize(window, size, size + 1);
        setUpMVP(size[0], size[1]);

        if(renderer != nullptr){
            camera.update();
            
            renderer->Update(currentTime);
            
            for (auto& obj : objects) {
                renderer->Draw(*obj);
            }
            
            renderer->Draw(*model);
        }
    }
    
    virtual void WindowSizeDidChange(GLFWwindow* window, int width, int height) noexcept override{
        setUpMVP(width, height);
    }
    
    virtual void Terminate() override{
        Application::Terminate();
        
    }
    
private:

    void setUpMVP(int width, int height){

        const float radius = 12.0;
        const float rad = _time * 75 / 180.0 * M_PI;
        const float origin[2] = {0.f, 11.f};
        camera.transform.translation = {static_cast<float>(cos(rad) * radius) + origin[0], 5.0, static_cast<float>(sin(rad) * radius) + origin[1]};
        camera.aspect = width / (float)height;
    }
};

int main(int argc, char** argv){

    using namespace MeowEngine;
    std::shared_ptr<Render> renderer =std::make_shared<Render>();
    MyApplication app;
    if (app.Init(renderer) == 0) {
        
        app.Run();
    }

    app.Terminate();
  
    return 0;
}
