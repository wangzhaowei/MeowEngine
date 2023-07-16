//
//  Triangle.cpp
//  GL
//
//  Created by 王昭威 on 2023/7/13.
//

#include "Triangle.hpp"
#include "TextureController.hpp"

//std::string getPath(){
//
//}"3.3.shader.vs", "3.3.shader.fs"

namespace MeowEngine {

Triangle::Triangle() noexcept: VAO(-1), VBO(-1), shader("/Volumes/D50 SSD/Projects/GL/GL/Shaders/ShaderSources/VertexShader.vs", "/Volumes/D50 SSD/Projects/GL/GL/Shaders/ShaderSources/FragmentShader.fs"){
    
    float vertices[] = {
        // positions         // colors              //  UV
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  1, 0,   // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  0, 0,   // bottom left
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   0.5, 1,    // top
    };
    
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    //  UV
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    
    glBindVertexArray(0);
    
    auto makeTexture = [](GLuint& texture, GLenum texSlot, unsigned char* pixel, int width = 256, int height = 256){
        
        glGenTextures(1, &texture);
        glActiveTexture(texSlot);
        glBindTexture(GL_TEXTURE_2D, texture);
        
        //     set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);    // set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixel);
        glGenerateMipmap(GL_TEXTURE_2D);
    };
    
    auto ret = MeowEngine::TextureController::shared()->loadImage("/Volumes/D50 SSD/Projects/GL/GL/wall.jpeg");
    
    if(ret.has_value()){
        auto wallTex = ret.value();
        makeTexture(textures[0], GL_TEXTURE0, wallTex.getBuffer(), wallTex.getWidth(), wallTex.getHeight());
    }
    unsigned char pix[256 * 256 * 3] = {0};
    
    for (size_t i = 0; i < 256 * 256 * 3; i += 3) {
        pix[i] = 0;
        pix[i + 1] = 255;
        pix[i + 2] = 0;
    }
    
    makeTexture(textures[1], GL_TEXTURE1, pix);

    shader.use();
    
    glUniform1i(glGetUniformLocation(shader.program, "diffuse"), 0);
    glUniform1i(glGetUniformLocation(shader.program, "diffuse2"), 1);
}

Triangle::~Triangle(){
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

void Triangle::render(){

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    
    shader.use();
    
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
//    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);
}
}
