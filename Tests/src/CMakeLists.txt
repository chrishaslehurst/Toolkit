cmake_minimum_required(VERSION 3.2)
project(ToolkitTests VERSION 1.0.0 LANGUAGES C CXX)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../ThirdParty)

add_executable(Tests DelegateTests.cpp)
add_subdirectory(${LIB_DIR}/Catch2 ${CMAKE_CURRENT_BINARY_DIR}/Catch2)
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)

add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/../../Toolkit/src ${CMAKE_CURRENT_BINARY_DIR}/Toolkit)
target_link_libraries(Tests PRIVATE Toolkit)
target_compile_features(Tests PRIVATE cxx_std_17)

include(CTest)
include(Catch)
catch_discover_tests(Tests)
enable_testing()

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Tests)
set_property(TARGET Tests PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

set_target_properties(Tests PROPERTIES FOLDER "Tests")
set_target_properties(Catch2 PROPERTIES FOLDER "Tests")
set_target_properties(Catch2WithMain PROPERTIES FOLDER "Tests")