cmake_minimum_required(VERSION 3.10)
project(kaleidoscope)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE LIB_FILES lib/**/*.cpp)

set(SOURCE_FILES main.cpp ${LIB_FILES})

add_executable(kaleidoscope ${SOURCE_FILES})