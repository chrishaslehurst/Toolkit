cmake_minimum_required(VERSION 3.2)

add_library(Engine
            Game.cpp ../include/Game.h
            Input.cpp ../include/Input.h
            Components/2DRenderableComponent.cpp ../include/Components/2DRenderableComponent.h)

#include our own headers
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set(MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../Libs)

#include Core module headers
target_include_directories(Engine PUBLIC ${MODULES_DIR}/Core/include)
#add the core module project subdirectory as a PUBLIC dependency
add_subdirectory( ${MODULES_DIR}/Core/src ${CMAKE_CURRENT_BINARY_DIR}/Core )
target_link_libraries(Engine PUBLIC Core)

#include Render module headers
target_include_directories(Engine PRIVATE ${MODULES_DIR}/Render/include)
#add the render module project subdirectory as a private dependency
add_subdirectory( ${MODULES_DIR}/Render/src ${CMAKE_CURRENT_BINARY_DIR}/Render )
target_link_libraries(Engine PRIVATE Render)

#include GLFW headers for input handling
target_include_directories(Engine PRIVATE ${LIB_DIR}/GLFW/include)
target_link_libraries(Engine PRIVATE glfw)

set_target_properties(Engine PROPERTIES FOLDER "Argent")
set_target_properties(Render PROPERTIES FOLDER "Argent")
set_target_properties(Core PROPERTIES FOLDER "Argent")