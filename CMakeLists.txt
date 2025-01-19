cmake_minimum_required(VERSION 3.10)
project(MyPass)

find_package(LLVM REQUIRED CONFIG)

set(CMAKE_CXX_STANDARD 17 CACHE STRING "")

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})

message("LLVM_DEFINITIONS: ${LLVM_DEFINITIONS}")
message("LLVM_DEFINITIONS_LIST: ${LLVM_DEFINITIONS_LIST}")
message("LLVM_LIBRARY_DIR: ${LLVM_LIBRARY_DIR}")

add_subdirectory(MyPass)

