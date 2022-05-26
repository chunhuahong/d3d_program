cmake_minimum_required (VERSION 3.16)

project("d3dProgram")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE "Debug")

######## main program ########
add_executable(d3dProgram src/main.cpp)