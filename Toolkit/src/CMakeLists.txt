cmake_minimum_required(VERSION 3.2)

add_library(Toolkit STATIC
            Core/System.cpp ../include/Core/System.h
            Core/Input.cpp ../include/Core/Input.h
            Core/GLCallbacks.cpp ../include/Core/GLCallbacks.h
            Rendering/Window.cpp ../include/Rendering/Window.h 
            Rendering/Utils.cpp ../include/Rendering/Utils.h
            Core/Delegate.cpp ../include/Core/Delegate.h  ../include/Core/Defines.h  ../include/Core/CoreMinimal.h
            Core/Log.cpp ../include/Core/Log.h 
            ../include/Core/TKTypeTraits.h)

#include our own headers
target_include_directories(Toolkit PUBLIC    ${CMAKE_CURRENT_SOURCE_DIR}/../include 
                                            ${CMAKE_CURRENT_SOURCE_DIR}/../include/Core 
                                            ${CMAKE_CURRENT_SOURCE_DIR}/../include/Rendering)

set(MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../ThirdParty)

set_target_properties(Toolkit PROPERTIES FOLDER "Toolkit")
target_compile_features(Toolkit PRIVATE cxx_std_17)

#include GLFW headers for input handling
target_include_directories(Toolkit PRIVATE ${LIB_DIR}/GLFW/include)
target_link_libraries(Toolkit PRIVATE glfw)

#add the glfw project subdirectory as a private dependency
add_subdirectory( ${LIB_DIR}/GLFW ${CMAKE_CURRENT_BINARY_DIR}/glfw )
set_target_properties(glfw PROPERTIES FOLDER "Third Party")

#include GLAD headers
add_library(GLAD ${LIB_DIR}/GLAD/src/glad.c)
target_include_directories(GLAD PRIVATE ${LIB_DIR}/GLAD/include)
target_include_directories(Toolkit PRIVATE ${LIB_DIR}/GLAD/include)
target_link_libraries(Toolkit PRIVATE GLAD)

set_target_properties(GLAD PROPERTIES FOLDER "Third Party")

#include spdlog
add_subdirectory( ${LIB_DIR}/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog )
target_link_libraries(Toolkit PUBLIC spdlog)

set_target_properties(spdlog PROPERTIES FOLDER "Third Party")