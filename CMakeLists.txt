cmake_minimum_required(VERSION 3.22)
project(CLogger VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the library
add_library(CLogger
    src/CLogger.cpp
    src/CLogConfig.cpp
)

# Include directories
target_include_directories(CLogger PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Add installation rules
install(TARGETS CLogger
    EXPORT CLoggerTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)

# Export the library for use in other projects
install(EXPORT CLoggerTargets
    FILE CLoggerTargets.cmake
    NAMESPACE CLogger::
    DESTINATION lib/cmake/CLogger
)

# Add a package configuration file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/CLoggerConfigVersion.cmake"
    VERSION ${CMAKE_PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/CLoggerConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/CLoggerConfig.cmake"
    @ONLY
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/CLoggerConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/CLoggerConfigVersion.cmake"
    DESTINATION lib/cmake/CLogger
)
