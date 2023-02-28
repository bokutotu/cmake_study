cmake_minimum_required(VERSION 3.9)
set(LIBRARY_NAME lib2)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

project(${LIBRARY_NAME} VERSION 1.0.1 DESCRIPTION "mylib description")

include(GNUInstallDirs)
add_library(${LIBRARY_NAME} SHARED src/lib2.cpp)
set_target_properties(${LIBRARY_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER include/lib2.h)
target_include_directories(${LIBRARY_NAME} PRIVATE .)

target_link_libraries(${LIBRARY_NAME} PRIVATE shared_lib)
target_include_directories(${LIBRARY_NAME} PRIVATE ../LIB/include)
target_link_directories(${LIBRARY_NAME} PRIVATE ../LIB/bin/)
