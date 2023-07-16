//
//  TextureController.hpp
//  GL
//
//  Created by 王昭威 on 2023/7/14.
//

#ifndef TextureController_hpp
#define TextureController_hpp

#include <stdio.h>
#include <memory>
#include <unordered_map>
#include <list>
#include "Texture.hpp"
#include "LRUCache.hpp"
#include "Bitmap.hpp"

namespace MeowEngine {

class TextureController{

public:
    static std::shared_ptr<TextureController> shared();
    
    LRUCache<std::string, std::shared_ptr<Bitmap>, 20> bufferCaches;
    
    std::optional<Texture> loadImage(const std::string& path);
    
protected:
    static std::shared_ptr<TextureController> instance;
};
}

#endif /* TextureController_hpp */
