cmake_minimum_required(VERSION 3.10)

project(GroundVehicle)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../../bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../../bin/)
set(EXECUTABLE_OUTPUT_PATH ../../../bin/)

set(SOURCES
        src/groundvehicle.cpp
        src/camel.cpp
        src/fastcamel.cpp
        src/centaur.cpp
        src/allterrainboots.cpp)

set(HEADERS
        include/groundvehicle.h
        include/camel.h
        include/fastcamel.h
        include/centaur.h
        include/allterrainboots.h)

add_library(GroundVehicle SHARED ${HEADERS} ${SOURCES})

target_link_libraries(GroundVehicle Vehicle)
