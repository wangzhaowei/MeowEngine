        #version 410 core                            
                                                               
        layout (location = 0) in vec3 pos; 
        layout (location = 1) in vec3 normal;
        layout (location = 2) in vec3 color;

        uniform mat4 model;
        layout(std140) uniform Matrices{ 
           float scale;
           mat4 view;
           mat4 projection;
        };
        layout(std140) uniform Matrices2{
           float scale2;
           mat4 view2;
           mat4 projection2;
        };
        out vec4 vsOut;
        out vec3 fragNormal;
        
        void main(void)                               
        {                                                      
           gl_Position = projection * view * model * vec4(pos.xyz, 1.0);
           vsOut = vec4(0.5, 0.25, 1, 1.0);                                            
           fragNormal = normal;                 
        }
