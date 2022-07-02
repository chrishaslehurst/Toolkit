cmake_minimum_required(VERSION 3.2)

add_library(Toolkit STATIC
            Core/System.cpp ../include/Core/System.h
            Core/Input.cpp ../include/Core/Input.h
            Core/GLCallbacks.cpp ../include/Core/GLCallbacks.h
            Rendering/Window.cpp ../include/Rendering/Window.h 
            Rendering/Utils.cpp ../include/Rendering/Utils.h
            Rendering/Shader.cpp ../include/Rendering/Shader.h
            Rendering/Material.cpp ../include/Rendering/Material.h
            Rendering/Mesh.cpp ../include/Rendering/Mesh.h
            Core/Delegate.cpp ../include/Core/Delegate.h  ../include/Core/Defines.h  ../include/Core/CoreMinimal.h
            Core/Log.cpp ../include/Core/Log.h 
            ../include/Core/TKTypeTraits.h)

#include our own headers
target_include_directories(Toolkit PUBLIC    ${CMAKE_CURRENT_SOURCE_DIR}/../include 
                                            ${CMAKE_CURRENT_SOURCE_DIR}/../include/Core 
                                            ${CMAKE_CURRENT_SOURCE_DIR}/../include/Rendering)

set(MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../ThirdParty)

add_library(imgui STATIC
            ${LIB_DIR}/imgui/imgui.cpp
            ${LIB_DIR}/imgui/imconfig.h
            ${LIB_DIR}/imgui/imgui.h
            ${LIB_DIR}/imgui/imgui_demo.cpp
            ${LIB_DIR}/imgui/imgui_draw.cpp
            ${LIB_DIR}/imgui/imgui_internal.h
            ${LIB_DIR}/imgui/imgui_tables.cpp
            ${LIB_DIR}/imgui/imgui_widgets.cpp
            ${LIB_DIR}/imgui/imstb_rectpack.h
            ${LIB_DIR}/imgui/imstb_textedit.h
            ${LIB_DIR}/imgui/imstb_truetype.h
            ${LIB_DIR}/imgui/backends/imgui_impl_glfw.cpp
            ${LIB_DIR}/imgui/backends/imgui_impl_opengl3.cpp)
            
target_include_directories(imgui PRIVATE ${LIB_DIR}/imgui ${LIB_DIR}/imgui/backends ${LIB_DIR}/glfw/include)


target_include_directories(Toolkit PUBLIC ${LIB_DIR}/imgui ${LIB_DIR}/imgui/backends)
target_link_libraries(Toolkit PUBLIC imgui)

set_target_properties(Toolkit PROPERTIES FOLDER "Toolkit")
target_compile_features(Toolkit PRIVATE cxx_std_17)

#include GLFW headers for input handling
target_include_directories(Toolkit PRIVATE ${LIB_DIR}/glfw/include)
target_link_libraries(Toolkit PRIVATE glfw)

#add the glfw project subdirectory as a private dependency
add_subdirectory( ${LIB_DIR}/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw )
set_target_properties(glfw PROPERTIES FOLDER "Third Party")

#include GLAD headers
add_subdirectory( ${LIB_DIR}/glad ${CMAKE_CURRENT_BINARY_DIR}/glad )
target_include_directories(glad PRIVATE ${LIB_DIR}/glad/include)
target_include_directories(Toolkit PRIVATE ${LIB_DIR}/glad/include)
target_link_libraries(Toolkit PRIVATE glad)

set_target_properties(glad PROPERTIES FOLDER "Third Party")
set_target_properties(glad-generate-files PROPERTIES FOLDER "Build Utilites")

#include spdlog
add_subdirectory( ${LIB_DIR}/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog )
target_link_libraries(Toolkit PUBLIC spdlog)

set_target_properties(spdlog PROPERTIES FOLDER "Third Party")

#copy assets
add_custom_target(copy_assets ALL
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/../content
                ${PROJECT_BINARY_DIR}/content
                COMMENT "Copying resources into binary directory")

add_dependencies(Toolkit copy_assets)

set_target_properties(copy_assets PROPERTIES FOLDER "Build Utilites")

#testing
enable_testing()

add_executable(ToolkitTests tests/DelegateTests.cpp)
target_link_libraries(ToolkitTests PRIVATE Toolkit)
add_subdirectory(${LIB_DIR}/Catch2 ${CMAKE_CURRENT_BINARY_DIR}/Catch2)
target_link_libraries(ToolkitTests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(ToolkitTests)

set_target_properties(ToolkitTests PROPERTIES FOLDER "Testing")
set_target_properties(Catch2 PROPERTIES FOLDER "Testing")
set_target_properties(Catch2WithMain PROPERTIES FOLDER "Testing")