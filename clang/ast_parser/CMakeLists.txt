cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 14)

project(ast_parser VERSION 0.1.0 LANGUAGES CXX)

set(LLVM_CONFIG "/usr/local/bin/llvm-config")

find_package(LLVM REQUIRED CONFIG)

llvm_map_components_to_libnames(LLVM_LIBS all)

set(LLVM_CXXFLAGS ${CMAKE_CXX_FLAGS} -fno-rtti -fcolor-diagnostics)

set(CLANG_LIBS clangAST clangFrontend clangBasic clangTooling)

add_executable(ast_parser ast_parser.cpp)
target_compile_options(ast_parser PUBLIC ${LLVM_CXXFLAGS})
target_link_libraries(ast_parser ${LLVM_LIBS} ${CLANG_LIBS})

add_executable(test test.cpp)