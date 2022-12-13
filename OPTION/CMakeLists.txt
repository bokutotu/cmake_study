cmake_minimum_required(VERSION 3.8)

project(CMakeOption)

option(GPU "GPUを有効にする" ON)

configure_file(
        "${PROJECT_SOURCE_DIR}/Config.h.in"
        "${PROJECT_BINARY_DIR}/Config.h"
)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(SWICH main.cpp "${PROJECT_BINARY_DIR}/Config.h")
