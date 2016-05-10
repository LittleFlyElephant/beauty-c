cmake_minimum_required(VERSION 3.5)
project(beauty_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp web/mongoose.h web/mongoose.c)
add_executable(beauty_c ${SOURCE_FILES})