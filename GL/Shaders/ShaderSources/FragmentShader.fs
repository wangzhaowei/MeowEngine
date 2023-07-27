#version 410 core   
out vec4 FragColor;

in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  
in vec2 texCoord;
uniform sampler2D diffuse;

void main()
{
    FragColor = mix(texture(diffuse, texCoord), vertexColor, 0.5);
    // FragColor = texture(diffuse, texCoord);
} 
