//
//  ShaderSrc.hpp
//  GL
//
//  Created by 王昭威 on 2023/7/13.
//

#ifndef ShaderSrc_h
#define ShaderSrc_h

//static const GLchar* triVertSrc[] =
//    {
//        "#version 410 core                             \n"
//        "                                                       \n"
//        "layout (location = 0) in vec3 pos; \n"
//        "layout (location = 1) in vec3 normal; \n"
//        "layout (location = 2) in vec3 color; \n"
//
//        "\n"
//        "uniform mat4 model;\n"
//        "layout(std140) uniform Matrices{ \n"
//        "   float scale;\n"
//        "   mat4 view;\n"
//        "   mat4 projection;\n"
//        "};\n"
//        "out vec4 vsOut;\n"
//        "out vec3 fragNormal;\n"
//        
//        "void main(void)                               \n"
//        "{                                                      \n"
//        "   gl_Position = projection * view * model * vec4(pos.xyz, 1.0);\n"
//        "   vsOut = vec4(0.5, 0.25, 1, 1.0);                                            \n"
//        "   fragNormal = normal;                 \n"
//        "}\n"
//    };
//
//static const GLchar* triFragSrc[] =
//    {
//        "#version 410 core                             \n"
//        "                                              \n"
//        "out vec4 color;                               \n"
//        "in vec4 vsOut;                       \n"
//        "in vec3 fragNormal; \n "
//        "uniform sampler2D tex;\n"
//        "                                              \n"
//        "void main(void)                               \n"
//        "{                                             \n"
////                "    color = vsOut.clr;         \n"
//        "   color = vec4(1, 1, 1, 1);\n"
//        "   color = vec4(fragNormal.xyz, 1);\n"
////        "color = texelFetch(tex, ivec2(gl_FragCoord.xy), 0);"
//        "}                                             \n"
//    };

#endif /* ShaderSrc_h */
