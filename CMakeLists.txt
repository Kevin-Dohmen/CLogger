cmake_minimum_required(VERSION 3.22)
project(clogger)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(CLogger
    src/CLogger.cpp
)

target_include_directories(clogger PUBLIC include)