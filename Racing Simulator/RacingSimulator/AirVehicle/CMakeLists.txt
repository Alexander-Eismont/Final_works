cmake_minimum_required(VERSION 3.10)

project(AirVehicle)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../../bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../../bin/)
set(EXECUTABLE_OUTPUT_PATH ../../../bin/)

set(SOURCES
        src/airvehicle.cpp
        src/carpetplain.cpp
        src/eagle.cpp
        src/broom.cpp)

set(HEADERS
        include/airvehicle.h
        include/carpetplain.h
        include/eagle.h
        include/broom.h)

add_library(AirVehicle SHARED ${HEADERS} ${SOURCES})

target_link_libraries(AirVehicle Vehicle)
