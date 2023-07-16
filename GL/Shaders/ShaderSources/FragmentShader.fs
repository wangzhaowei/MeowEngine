#version 410 core   
out vec4 FragColor;

in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  
in vec2 texCoord;

uniform sampler2D diffuse;
uniform sampler2D diffuse2;

void main()
{
    // FragColor = vertexColor;
    FragColor = mix(texture(diffuse, texCoord), texture(diffuse2, texCoord), 0.5);
    // FragColor = texture(diffuse, texCoord);
    // FragColor = vec4(texCoord.xy, 0, 1);
} 