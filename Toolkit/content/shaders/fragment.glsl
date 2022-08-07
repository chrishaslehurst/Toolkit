#version 330 core

//inputs
in vec4 vertexColour;
in vec2 vertexTexCoord;

//outputs
out vec4 fragColor;

uniform sampler2D ourTexture;

void main()
{
    fragColor = texture(ourTexture, vertexTexCoord);
} 