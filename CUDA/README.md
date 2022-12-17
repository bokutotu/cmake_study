# Build CUDA using CMake
https://developer.nvidia.com/blog/building-cuda-applications-cmake/
参考URL

## CMake
```cmake
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(cmake_and_cuda LANGUAGES CXX CUDA)
 
include(CTest)
 
add_library(particles STATIC
randomize.cpp
randomize.h
particle.cu
particle.h
v3.cu
v3.h
)
 
# Request that particles be built with -std=c++11
# As this is a public compile feature anything that links to 
# particles will also build with -std=c++11
target_compile_features(particles PUBLIC cxx_std_11)

# We need to explicitly state that we need all CUDA files in the 
# particle library to be built with -dc as the member functions 
# could be called by other libraries and executables
set_target_properties( particles
                   PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
 
add_executable(particle_test test.cu)
 
set_property(TARGET particle_test 
         PROPERTY CUDA_SEPARABLE_COMPILATION ON)
target_link_libraries(particle_test PRIVATE particles)
 
if(APPLE)
# We need to add the path to the driver (libcuda.dylib) as an rpath, 
# so that the static cuda runtime can find it at runtime.
set_property(TARGET particle_test 
           PROPERTY
           BUILD_RPATH ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES})
endif()
```

## コンパイルフラグ

cmake 3.8以上であれば、`nvcc`とc++コンパイラを用いてmakefileを作成できる
`-DCMAKE_CUDA_FLAG`で`nvcc`にフラグを渡すことができる。
```cmake
cmake -DCMAKE_CUDA_FLAGS=”-arch=sm_30” .
```
など

`CMAKE_CUDA_FLAGS`に` –cudart { none | shared | static }`を渡すことでどのruntimeを使用するかを選べる

## CMakeでcudaを使用する

```cmake
project(cmake_and_cuda LANGUAGES CXX CUDA)
```
で使用する言語を宣言している

## C++のLevelを設定
`target_compile_features(particles PUBLIC cxx_std_11)`でc++の使用するstdのバージョンを決定できる？
ドキュメント
https://cmake.org/cmake/help/latest/command/target_compile_features.html


