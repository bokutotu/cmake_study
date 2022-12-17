cmake_minimum_required(VERSION 3.8)

project(CUDA_CMAKE LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CUDA_STANDARD 14)

add_executable(MAIN main.cpp kernel.cu)
target_include_directories(MAIN PUBLIC /usr/local/cuda/include)
