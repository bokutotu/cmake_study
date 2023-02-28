cmake_minimum_required(VERSION 3.9)
set(LIBRARY_NAME shared_lib)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

project(${LIBRARY_NAME} VERSION 1.0.1 DESCRIPTION "mylib description")

include(GNUInstallDirs)
add_library(${LIBRARY_NAME} SHARED src/shard_lib.cpp)
set_target_properties(${LIBRARY_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER include/shared.h)
# configure_file(mylib.pc.in mylib.pc @ONLY)
target_include_directories(${LIBRARY_NAME} PRIVATE .)
# install(TARGETS LIBRARY_NAME
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
# install(FILES ${CMAKE_BINARY_DIR}/mylib.pc
#     DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
