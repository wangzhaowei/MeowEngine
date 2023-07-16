//
//  Shaders.cpp
//  GL
//
//  Created by 王昭威 on 2023/6/25.
//

#include "Shaders.hpp"

GLuint modelVertShader = 0;
GLuint modelFragShader = 0;

std::ostream& operator<< (std::ostream& out, const std::vector<char> v) {
    if ( !v.empty() ) {
        for (auto ch : v) {
            out << ch;
        }
    }
    return out;
}

