cmake_minimum_required(VERSION 3.10)

project(Vehicle)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../../bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../../bin/)
set(EXECUTABLE_OUTPUT_PATH ../../../bin/)

set(SOURCES
    src/vehicle.cpp)

set(HEADERS
    include/vehicle.h)

add_library(Vehicle SHARED ${HEADERS} ${SOURCES})
