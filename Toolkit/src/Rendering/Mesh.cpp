#include "Mesh.h"
#include "glad/glad.h"

#include "GLFW/glfw3.h"

namespace toolkit
{ 
    Mesh::Mesh() 
    { 
       
    }

    void Mesh::Draw() 
    {
        glBindVertexArray(vertexArrayObject);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    void Mesh::Setup() 
    {
        float vertices[] = {
            0.5f,  0.5f,  0.0f, 1.f, 0.f, 0.f, 1.f, 1.f, // top right
            0.5f,  -0.5f, 0.0f, 0.f, 1.f, 0.f, 1.f, 0.f, // bottom right
            -0.5f, -0.5f, 0.0f, 0.f, 0.f, 1.f, 0.f, 0.f,// bottom left
            -0.5f, 0.5f,  0.0f, 1.f, 1.f, 1.f, 0.f, 1.f// top left
        };
        unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };

        GLuint vertexBufferObject;

        glGenBuffers(1, &vertexBufferObject);
        glGenVertexArrays(1, &vertexArrayObject);
        glGenBuffers(1, &elementBufferObject);

        glBindVertexArray(vertexArrayObject);

        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // Vertex Attributes
        // position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        // texture attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);  


        glBindVertexArray(0);
    }

} // namespace toolkit
