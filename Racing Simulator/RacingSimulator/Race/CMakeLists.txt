cmake_minimum_required(VERSION 3.10)

project(Race)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../../bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../../bin/)
set(EXECUTABLE_OUTPUT_PATH ../../../bin/)

set(SOURCES 
	src/race.cpp)

set(HEADERS 
	include/race.h)

add_library(Race SHARED ${HEADERS} ${SOURCES})

target_link_libraries(Race Vehicle RacingException)
