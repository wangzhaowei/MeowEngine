//
//  Bitmap.hpp
//  GL
//
//  Created by Felis Meow on 2023/7/14.
//

#ifndef Bitmap_hpp
#define Bitmap_hpp

#include <stdio.h>

namespace MeowEngine {

class Bitmap{
    friend class Texture;
private:
    const std::string _key;
protected:
    unsigned char* buffer = nullptr;
    int _width, _height, _bpp;
    
public:
    
    Bitmap(unsigned char* buf, int width, int height, int bpp, const std::string& key): _key(key), buffer(buf), _width(width), _height(height), _bpp(bpp){};
    virtual ~Bitmap();
    
    unsigned char* getBuffer();
};

}


#endif /* Bitmap_hpp */
