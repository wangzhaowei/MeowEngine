//
//  Texture.hpp
//  GL
//
//  Created by Felis Meow on 2023/7/14.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <string>
#include <memory>
#include "Bitmap.hpp"
#include <OpenGL/gl3.h>
#include <optional>

namespace MeowEngine {
class Texture{
protected:
    const std::shared_ptr<Bitmap> _bitmap;
    
    std::optional<GLuint> _textureID = std::nullopt;
    
public:
    
    void setTexture(GLenum texSlot, GLenum target){
        if (_textureID.has_value()) {
            glActiveTexture(texSlot);
            glBindTexture(target, _textureID.value());
        }
    }
    
    int getWidth(){
        return getBitmap()->_width;
    }
    
    int getHeight(){
        return getBitmap()->_height;
    }
    
    uint8_t* getBuffer(){
        return getBitmap()->getBuffer();
    }
    
    std::shared_ptr<Bitmap> getBitmap(){
        return _bitmap;
    }
    
    Texture(std::shared_ptr<Bitmap>& bitmapPtr);
    
    virtual ~Texture(){
        
    }
};
}

#endif /* Texture_hpp */
