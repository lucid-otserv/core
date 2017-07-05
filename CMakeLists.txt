cmake_minimum_required (VERSION 3.6)
project (Tutorial)

if (${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
  message(FATAL_ERROR "Run cmake from ./build directory") 
endif ()

set(CMAKE_CXX_STANDARD 11)
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/../cmake)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../build/bin)

file(GLOB_RECURSE SRC_FILES
    "${PROJECT_SOURCE_DIR}/*.cpp"
    "${PROJECT_SOURCE_DIR}/*.hpp"
)

add_executable(Tutorial ${SRC_FILES})

find_package(CAF COMPONENTS core io) 
if (CAF_FOUND) 
  include_directories(${CAF_INCLUDE_DIRS}) 
else () 
  message(FATAL_ERROR "Could not find C++ Actor Framework") 
endif () 

target_link_libraries(Tutorial 
  ${CMAKE_DL_LIBS} 
  ${CAF_LIBRARY_CORE} 
  ${CAF_LIBRARY_IO} 
)