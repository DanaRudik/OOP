cmake_minimum_required(VERSION 3.5.0)
project(BitArray VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(BitArray main.cpp BitArray.h TwoBitArray.cpp BitArrayConstructors.cpp BitArrayManipulation.cpp BitArrayOperators.cpp BitArraySetters.cpp BitArrayChecks.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(BitArray PRIVATE gtest gtest_main)
enable_testing()
