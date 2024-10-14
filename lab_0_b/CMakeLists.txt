cmake_minimum_required(VERSION 3.5.0)
project(lab0b VERSION 0.1.0 LANGUAGES C CXX)

SET(MY_VARIABLE "option_value" CACHE STRING "./a.txt")

FILE(COPY "resources/a.txt" DESTINATION "${CMAKE_BINARY_DIR}/resources")
FILE(COPY "resources/output.csv" DESTINATION "${CMAKE_BINARY_DIR}/resources")

add_executable(lab0b)
target_sources(lab0b PRIVATE 
    "models/entity.h" 
    "models/entity.cpp"
     
    main.cpp 
)


