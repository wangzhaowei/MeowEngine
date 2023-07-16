//
//  Texture.hpp
//  GL
//
//  Created by 王昭威 on 2023/7/14.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <string>
#include <memory>
#include "Bitmap.hpp"

namespace MeowEngine {
class Texture{
protected:
    const std::shared_ptr<Bitmap> _bitmap;
    
public:
    
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
    
    Texture(std::shared_ptr<Bitmap>& bitmapPtr): _bitmap(bitmapPtr){
        
    }
    
    virtual ~Texture(){
        
    }
};
}

#endif /* Texture_hpp */
