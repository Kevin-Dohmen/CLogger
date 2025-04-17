cmake_minimum_required(VERSION 3.22)
project(CLogger)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the library
add_library(CLogger
    src/CLogger.cpp
)

# # Add an executable for testing
# add_executable(CLoggerTest
#     src/main.cpp # Create this file for testing purposes
# )

# # Link the library to the executable
# target_link_libraries(CLoggerTest CLogger)

# Include directories
target_include_directories(CLogger PUBLIC include)