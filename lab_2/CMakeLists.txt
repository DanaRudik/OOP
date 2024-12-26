cmake_minimum_required(VERSION 3.5.0)
project(Life VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Life main.cpp Life.h Life.cpp Field.h Field.cpp)

include(CTest)
enable_testing()

