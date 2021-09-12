cmake_minimum_required(VERSION 3.2)

project(EngineTestingApp VERSION 1.0.0 LANGUAGES C CXX)

add_executable(EngineTest
  main.cpp
)

add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/../../Engine/src ${CMAKE_CURRENT_BINARY_DIR}/Engine)
target_link_libraries(EngineTest PRIVATE Engine)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT EngineTest)
set_property(TARGET EngineTest PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_SUPPRESS_REGENERATION true)