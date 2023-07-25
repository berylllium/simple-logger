cmake_minimum_required(VERSION 3.21)

project(simple-logger)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(test/)

set(SOURCES
	src/simple-logger.cpp
)

add_library(simple-logger STATIC ${SOURCES})
target_include_directories(simple-logger PUBLIC include/)
