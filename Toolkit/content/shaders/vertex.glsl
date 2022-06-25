#version 330 core
//inputs
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 colour;

//outputs
out vec4 vertexColour;

void main()
{
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
    vertexColour = vec4(colour, 1.0);
}