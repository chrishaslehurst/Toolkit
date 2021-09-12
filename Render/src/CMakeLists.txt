cmake_minimum_required(VERSION 3.2)

add_library(Render
            WindowGL.cpp WindowGL.h Window.cpp ../include/Window.h 
            Utils.cpp ../include/Utils.h
            Renderables/Shape2D.cpp ../include/Renderables/Shape2D.h)

#include our own headers
target_include_directories(Render PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs)

#include Core module headers
target_include_directories(Render PUBLIC ${MODULES_DIR}/Core/include)
#add the core module project subdirectory as a PUBLIC dependency
target_link_libraries(Render PUBLIC Core)

#include GLFW headers
target_include_directories(Render PRIVATE ${LIB_DIR}/GLFW/include)
#add the glfw project subdirectory as a private dependency
add_subdirectory( ${LIB_DIR}/GLFW ${CMAKE_CURRENT_BINARY_DIR}/glfw )
target_link_libraries(Render PRIVATE glfw)

#include GLAD headers
add_library(GLAD ${LIB_DIR}/GLAD/src/glad.c)
target_include_directories(GLAD PRIVATE ${LIB_DIR}/GLAD/include)
target_include_directories(Render PRIVATE ${LIB_DIR}/GLAD/include)
target_link_libraries(Render PRIVATE GLAD)

set_target_properties(GLAD PROPERTIES FOLDER "Third Party")