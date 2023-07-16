#version 410 core                            

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 UV;
  
out vec4 vertexColor; // specify a color output to the fragment shader
out vec2 texCoord;

void main()
{
    gl_Position = vec4(position.xyz, 1.0); // see how we directly give a vec3 to vec4's constructor
    vertexColor = vec4(color, 1.0); // set the output variable to a dark-red color
    texCoord = UV;
}