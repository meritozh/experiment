cmake_minimum_required(VERSION 3.2.0)

set(ENV{CXX} /usr/local/bin/clang++)
set(ENV{CC} /usr/local/bin/clang)

project(astconsumer)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti -fcolor-diagnostics")

set(LLVM_CONFIG "/usr/local/bin/llvm-config")

execute_process(COMMAND ${LLVM_CONFIG} --cxxflags
                OUTPUT_VARIABLE LLVM_CXXFLAGS
                OUTPUT_STRIP_TRAILING_WHITESPACE)

execute_process(COMMAND ${LLVM_CONFIG} --libs --system-libs
                OUTPUT_VARIABLE LLVM_LDFLAGS
                OUTPUT_STRIP_TRAILING_WHITESPACE)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_CXXFLAGS}")

set(CLANG_LIBS clangTooling clangAST clangBasic clangFrontend)

# add_library(astconsumer SHARED
            # astconsumer.cpp)
add_executable(astconsumer astconsumer.cpp)

target_link_libraries(astconsumer ${LLVM_CXXFLAGS} ${LLVM_LDFLAGS} ${CLANG_LIBS})
