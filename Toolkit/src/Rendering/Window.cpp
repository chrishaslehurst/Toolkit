#include "Rendering/Window.h"
#include "GLCallbacks.h"
#include "Utils.h"
#include "glad/glad.h"

#include "GLFW/glfw3.h"

namespace toolkit
{
    GLuint createShaderProgram()
    {
        // Vertex Shader
        std::string vertexShaderSource = utilities::LoadFile("content/shaders/vertex.glsl");
        // #todo-ch 10/04/2022:can we improve this?
        const char *vertexShaderSourceAsCharArray = vertexShaderSource.c_str();
        GLuint vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSourceAsCharArray, nullptr);
        glCompileShader(vertexShader);

        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            TK_CORE_ERROR("Vertex shader compilation failed:\n {}", infoLog);
        }

        // Fragment Shader
        std::string fragmentShaderSource = utilities::LoadFile("content/shaders/fragment.glsl");
        const char *fragmentShaderSourceAsCharArray = fragmentShaderSource.c_str();
        GLuint fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSourceAsCharArray, nullptr);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            TK_CORE_ERROR("Fragment shader compilation failed:\n {}", infoLog);
        }

        // Create Shader Program
        GLuint shaderProgram;
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
            TK_CORE_ERROR("Shader program link failed:\n {}", infoLog);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return shaderProgram;
    }

    Window::Window(u32 width, u32 height, const char *windowName, void *system)
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwSetErrorCallback(toolkit::errorCallback);

        window = glfwCreateWindow(width, height, windowName, nullptr, nullptr);
        if (!window)
        {
            TK_CORE_ERROR("Failed to create GLFW window");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            TK_CORE_ERROR("Failed to initialize GLAD");
            return;
        }

        glViewport(0, 0, width, height);
        glClearColor(0.15f, 0.6f, 0.4f, 1.0f);
        glfwSetWindowUserPointer(window, system);
        glfwSetKeyCallback(window, toolkit::keyCallback);
        glfwSetFramebufferSizeCallback(window, toolkit::FrameBufferSizeCallback);

        // begin triangle draw...
        float vertices[] = {
            0.5f,  0.5f,  0.0f, // top right
            0.5f,  -0.5f, 0.0f, // bottom right
            -0.5f, -0.5f, 0.0f, // bottom left
            -0.5f, 0.5f,  0.0f  // top left
        };
        unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };
        // the id of the vertex buffer
        GLuint vertexBufferObject;
        // generates 1 buffer and puts the id into vertexBufferObject
        glGenBuffers(1, &vertexBufferObject);
        glGenVertexArrays(1, &vertexArrayObject);
        glGenBuffers(1, &elementBufferObject);
        
        glBindVertexArray(vertexArrayObject);
       
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
       
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 

        // Vertex Attributes
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);
        
        glBindVertexArray(0);
        
        shaderProgram = createShaderProgram();

        // end triangle draw...
        return;
    }

    bool Window::Update()
    {
        if (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);
            //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //Wireframe

            glUseProgram(shaderProgram);
            glBindVertexArray(vertexArrayObject);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);

            glfwSwapBuffers(window);
            glfwPollEvents();
            return true;
        }
        else
        {
            glfwDestroyWindow(window);
            glfwTerminate();
            return false;
        }
    }

    void FrameBufferSizeCallback(GLFWwindow *window, s32 width, s32 height) { glViewport(0, 0, width, height); }

} // namespace toolkit