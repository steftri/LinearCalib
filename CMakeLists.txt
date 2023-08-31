cmake_minimum_required(VERSION 3.14)

project(LinearCalib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ask for all warnings and strict compliance with the standard
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic")

add_library(LinearCalib STATIC
  src/linearcalib.h
  src/linearcalib.cpp
)

target_compile_definitions(LinearCalib PRIVATE LINEARCALIB_LIBRARY)
target_include_directories(LinearCalib PUBLIC src)
