cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RacingSimulator)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin/)
set(EXECUTABLE_OUTPUT_PATH ../../bin/)

include_directories(AirVehicle/include)
include_directories(GroundVehicle/include)
include_directories(Race/include)
include_directories(RacingException/include)
include_directories(Vehicle/include)

add_executable(RacingSimulator "RacingSimulator.cpp")

add_subdirectory(AirVehicle)
add_subdirectory(GroundVehicle)
add_subdirectory(Race)
add_subdirectory(RacingException)
add_subdirectory(Vehicle)

target_link_libraries(RacingSimulator 
						Vehicle 
						GroundVehicle 
						AirVehicle
						Race
						RacingException)
