        #version 410 core                             
                                                      
        out vec4 color;                               
        in vec4 vsOut;                       
        in vec3 fragNormal; 
        uniform sampler2D tex;
                                                      
        void main(void)                               
        {                                             
//                "    color = vsOut.clr;         \n"
           color = vec4(1, 1, 1, 1);
           color = vec4(fragNormal.xyz, 1);
//        "color = texelFetch(tex, ivec2(gl_FragCoord.xy), 0);"
        }                