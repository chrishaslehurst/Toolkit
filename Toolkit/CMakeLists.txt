cmake_minimum_required(VERSION 3.2)

file(GLOB_RECURSE _source_list 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h*" 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp*" 
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.cpp"
    )

add_library(Toolkit ${_source_list})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/ FILES ${_source_list})

#include our own headers
target_include_directories(Toolkit PUBLIC   ${CMAKE_CURRENT_SOURCE_DIR}/include 
                                            ${CMAKE_CURRENT_SOURCE_DIR}/include/Core 
                                            ${CMAKE_CURRENT_SOURCE_DIR}/include/Math 
                                            ${CMAKE_CURRENT_SOURCE_DIR}/include/Rendering)

set(MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty)

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
target_compile_features(Toolkit PRIVATE cxx_std_20)

#include GLFW headers for input handling
target_include_directories(Toolkit PUBLIC ${LIB_DIR}/glfw/include)
target_link_libraries(Toolkit PUBLIC glfw)

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

#include stb_image
target_include_directories(Toolkit PRIVATE ${LIB_DIR}/stb)

#copy assets
add_custom_target(copy_assets ALL
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/content
                ${PROJECT_BINARY_DIR}/content
                COMMENT "Copying resources into binary directory")

add_dependencies(Toolkit copy_assets)

set_target_properties(copy_assets PROPERTIES FOLDER "Build Utilites")

#testing
enable_testing()

file(GLOB_RECURSE _test_list 
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.h*" 
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp*" 
    )

add_executable(ToolkitTests ${_test_list})
target_compile_features(ToolkitTests PRIVATE cxx_std_20)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/ FILES ${_source_list})
target_link_libraries(ToolkitTests PRIVATE Toolkit)
add_subdirectory(${LIB_DIR}/Catch2 ${CMAKE_CURRENT_BINARY_DIR}/Catch2)
target_link_libraries(ToolkitTests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(ToolkitTests)

set_target_properties(ToolkitTests PROPERTIES FOLDER "Testing")
set_target_properties(Catch2 PROPERTIES FOLDER "Testing")
set_target_properties(Catch2WithMain PROPERTIES FOLDER "Testing")