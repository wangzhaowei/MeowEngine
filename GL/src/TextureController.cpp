//
//  TextureController.cpp
//  GL
//
//  Created by 王昭威 on 2023/7/14.
//

#include "TextureController.hpp"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <optional>

namespace MyGL {

Bitmap::~Bitmap(){
    stbi_image_free(buffer);
    buffer = nullptr;
}

unsigned char* Bitmap::getBuffer(){
    return buffer;
}

std::shared_ptr<TextureController> TextureController::instance = nullptr;

std::shared_ptr<TextureController> TextureController::shared(){
    if (instance == nullptr) {
        instance = std::make_shared<TextureController>();
    }
    
    return instance;
}

std::optional<Texture> TextureController::loadImage(const std::string &path){

    auto buf = bufferCaches.get(path);
    std::shared_ptr<Bitmap> bitmap = buf.value_or(nullptr);
    if (bitmap == nullptr) {
        stbi_set_flip_vertically_on_load(true);
        int width, height, bpp;
        uint8_t* rgbImage = stbi_load(path.c_str(), &width, &height, &bpp, 0);
        if (rgbImage == nullptr) {
            return {};
        }
        bitmap = std::make_shared<Bitmap>(rgbImage, width, height, bpp);
        bufferCaches.put(path, bitmap);
    }
    
    return bitmap;
}
}
