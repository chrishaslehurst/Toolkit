#include "Rendering/Window.h"
#include "GLCallbacks.h"
#include "glad/glad.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "GLFW/glfw3.h"

namespace toolkit
{

    Window::Window(u32 width, u32 height, const char *windowName, void *system)
    {
        glfwInit();
        const char *glsl_version = "#version 150";
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

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        (void)io;
        // io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        // io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        // ImGui::StyleColorsClassic();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);

        // Load Fonts
        // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use
        // ImGui::PushFont()/PopFont() to select them.
        // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among
        // multiple.
        // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application
        // (e.g. use an assertion, or display an error and quit).
        // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling
        // ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
        // - Read 'docs/FONTS.md' for more instructions and details.
        // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double
        // backslash \\ !
        // io.Fonts->AddFontDefault();
        // io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
        // io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
        // io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
        // io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
        // ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL,
        // io.Fonts->GetGlyphRangesJapanese()); IM_ASSERT(font != NULL);


        glViewport(0, 0, width, height);
        glClearColor(0.15f, 0.6f, 0.4f, 1.0f);
        glfwSetWindowUserPointer(window, system);
        glfwSetKeyCallback(window, toolkit::keyCallback);
        glfwSetFramebufferSizeCallback(window, toolkit::FrameBufferSizeCallback);

        square.Setup();

        MaterialDef def;
        def.vertexShaderPath = "content/shaders/vertex.glsl";
        def.fragmentShaderPath = "content/shaders/fragment.glsl";
        mat.Compile(def);
    }

    bool Window::Update()
    {
        if (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);
            //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //Wireframe
            
            mat.Use();
            square.Draw();

            glfwPollEvents();
            
            // Start the Dear ImGui frame
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            ImGui::ShowDemoWindow(&showDemoWindow);
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            glfwSwapBuffers(window);

            return true;
        }
        else
        {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();

            glfwDestroyWindow(window);
            glfwTerminate();
            return false;
        }
    }

    void FrameBufferSizeCallback(GLFWwindow *window, s32 width, s32 height) { glViewport(0, 0, width, height); }

} // namespace toolkit