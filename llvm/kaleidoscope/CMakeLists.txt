cmake_minimum_required(VERSION 3.10)
project(kaleidoscope)

set(CMAKE_CXX_STANDARD 17)

set(LIB_FILES
        lib/Lexer.cpp)

set(SOURCE_FILES main.cpp ${LIB_FILES})

add_executable(kaleidoscope ${SOURCE_FILES})