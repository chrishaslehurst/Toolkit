cmake_minimum_required(VERSION 3.2)
project(Engine)

add_library(Engine
            Game.cpp ../include/Game.h)

#include our own headers
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set(MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../Libs)

#include Render module headers
target_include_directories(Engine PRIVATE ${MODULES_DIR}/Render/include)
#add the render module project subdirectory as a private dependency
add_subdirectory( ${MODULES_DIR}/Render/src ${CMAKE_CURRENT_BINARY_DIR}/Render )
target_link_libraries(Engine PRIVATE Render)

#include GLFW headers for input handling
target_include_directories(Engine PRIVATE ${LIB_DIR}/GLFW/include)
target_link_libraries(Engine PRIVATE glfw)