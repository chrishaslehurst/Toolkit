cmake_minimum_required(VERSION 3.2)
project(Render)

add_library(Render
            Window.cpp ../include/Window.h
            Utils.cpp ../include/Utils.h)

#include our own headers
target_include_directories(Render PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../Libs)

#include GLFW headers
target_include_directories(Render PRIVATE ${LIB_DIR}/GLFW/include)
#add the glfw project subdirectory as a private dependency
add_subdirectory( ${LIB_DIR}/GLFW ${CMAKE_CURRENT_BINARY_DIR}/glfw )
target_link_libraries(Render PRIVATE glfw)

add_library(GLAD ${LIB_DIR}/GLAD/src/glad.c)
target_include_directories(GLAD PRIVATE ${LIB_DIR}/GLAD/include)
target_include_directories(Render PRIVATE ${LIB_DIR}/GLAD/include)
target_link_libraries(Render PRIVATE GLAD)