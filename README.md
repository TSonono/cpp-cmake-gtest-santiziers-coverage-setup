# A cross-platform CMake C++ setup with streamlined sanitizer and coverage integration

## Introduction

The purpose of the repository is to show one approach of setting up a C/C++ project in CMake. The setup offers convenient ways of applying nice features such as coverage reports, gtest integration and sanitizers.

## Requirements

- Linux (tested on ubuntu)
- A C++ compiler
- CMake
- gcov and lcov

## Installation

```bash
mkdir build
cd build
cmake ..
make
```

## Usage

This setup includes a sample library which only has a binary search method. For this library, a unit test file using gtest confirms the functionality.

### Features

Some flags should be passed to the cmake command for the extra features in this setup

| Flags                   | Descripton                                                                            |
| ------------------------|:-------------------------------------------------------------------------------------:|
| -DBUILD_TESTS=On        | Build the google test unit tests                                                      |
| -DWITH_COVERAGE=On      | Build the project with coverage data                                                  |
| -DSANITIZE_ADDRESS=On   | Add ASAN with `add_sanitizers` in cmake to a executeable or library                   |
| -DSANITIZE_UNDEFINED=On | Add UBSAN with `add_sanitizers` in cmake to a executeable or library                  |
| -DSANITIZE_MEMORY=On    | Add MSAN with `add_sanitizers` in cmake to a executeable or library (only with clang) |
| -DSANITIZE_THREAD =On   | Add TSAN with `add_sanitizers` in cmake to a executeable or library                   |

An example call to cmake would then be

```bash
cmake -DCMAKE_BUILD_TYPE=Debug -DSANITIZE_ADDRESS=On -DBUILD_TESTS=ON -DWITH_COVERAGE=ON ..
```

Note, you can't use all sanitizers at the same time. Same restrictions apply as compiling and linking with the sanitizers manually (without this setup).

### Run

To build the project after running the CMake script, one would simply run the command `make` in the `build/` directory. To run the test(s), 
one would run the command `ctest`. If a test fails, one can run a individual test like so `./tests/binary_search_test`. This would provide the output from the test and potentially the sanitizers if they find an error.
