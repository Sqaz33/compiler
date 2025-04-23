cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(llvm_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs core support)

add_executable(llvm_example main.cpp)

target_link_libraries(llvm_example ${llvm_libs})
