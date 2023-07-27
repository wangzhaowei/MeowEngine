#version 410 core                            

subroutine vec4 Light(vec4 color);

subroutine (Light) vec4 diffuseLight(vec4 color){
    return vec4(1, 1, 1, 1);
}

subroutine (Light) vec4 diffuseLight2(vec4 color){
    return vec4(1, 0, 0, 1);
}

subroutine uniform Light lightFunc;

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 UV;
  
out vec4 vertexColor; // specify a color output to the fragment shader
out vec2 texCoord;

void main()
{
    vec4 vertLight = lightFunc(vec4( 1, 0, 0, 1));
    gl_Position = vec4(position.xyz, 1.0); // see how we directly give a vec3 to vec4's constructor
    vertexColor = vertLight; // set the output variable to a dark-red color
    texCoord = UV;
}
