cmake_minimum_required(VERSION 3.2)

add_library(Core
            Delegate.cpp ../include/Delegate.h 
            ../include/CoreMinimal.h ../include/Defines.h)

#include our own headers
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../ThirdParty)

add_subdirectory( ${LIB_DIR}/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog )
target_link_libraries(Core PRIVATE spdlog)

set_target_properties(spdlog PROPERTIES FOLDER "Third Party")