//
//  Texture.cpp
//  GL
//
//  Created by Felis Meow on 2023/7/14.
//

#include "Texture.hpp"

namespace MeowEngine {
Texture::Texture(std::shared_ptr<Bitmap>& bitmapPtr): _bitmap(bitmapPtr){
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
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 4);
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixel);
        glGenerateMipmap(GL_TEXTURE_2D);
    };
    
    if (_bitmap != nullptr) {
        GLuint id = 0;
        makeTexture(id, GL_TEXTURE0, _bitmap->buffer, _bitmap->_width, _bitmap->_width);
        _textureID = id;
    }
}
}
