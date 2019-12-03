cmake_minimum_required(VERSION 3.0)
project(algo)

option(BUILD_TESTS "Build the tests" OFF)
option(WITH_COVERAGE "Build the project with coverage data" OFF)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -Wshadow -Wcast-qual)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/sanitizers-cmake/cmake;${CMAKE_SOURCE_DIR}/cmake/" ${CMAKE_MODULE_PATH})

if(WITH_COVERAGE)
    include(CodeCoverage)
    APPEND_COVERAGE_COMPILER_FLAGS()
endif(WITH_COVERAGE)

find_package(Sanitizers)


add_subdirectory(src)

if(BUILD_TESTS)
    enable_testing()
    include(GoogleTest)
    include(AddTest)
    add_subdirectory(tests)
endif(BUILD_TESTS)