cmake_minimum_required(VERSION 3.4)
project(algo)

set (CMAKE_CXX_STANDARD 14)

option(BUILD_TESTS "Build the tests" OFF)
option(WITH_COVERAGE "Build the project with coverage data" OFF)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/sanitizers-cmake/cmake;${CMAKE_SOURCE_DIR}/cmake/;${CMAKE_SOURCE_DIR}/cmake/cmake-modules" ${CMAKE_MODULE_PATH})

if(WITH_COVERAGE)
    find_program(LLVMCOV_PATH llvm-cov)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang")
        if(LLVMCOV_PATH)
            set(GCOV_PATH "${CMAKE_CURRENT_SOURCE_DIR}/llvm-cov.sh")
        endif(LLVMCOV_PATH)
    endif()
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif(WITH_COVERAGE)

find_package(Sanitizers)

add_subdirectory(src)

if(BUILD_TESTS)
    enable_testing()
    include(GoogleTest)
    include(AddTest)
    add_subdirectory(tests)
endif(BUILD_TESTS)