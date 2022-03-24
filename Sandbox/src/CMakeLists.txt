cmake_minimum_required(VERSION 3.2)

project(Sandbox VERSION 1.0.0 LANGUAGES C CXX)

add_executable(Sandbox
  main.cpp
)

add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/../../Toolkit/src ${CMAKE_CURRENT_BINARY_DIR}/Toolkit)
target_link_libraries(Sandbox PRIVATE Toolkit)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)
set_property(TARGET Sandbox PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_SUPPRESS_REGENERATION true)