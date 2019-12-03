add_subdirectory(googletest)
set(COVERAGE_LCOV_EXCLUDES '${CMAKE_SOURCE_DIR}/tests/*' '/usr/include/*')


add_gtest_test(binary_search_test binary_search_test.cpp)
target_link_libraries(binary_search_test binary_search)
target_include_directories(binary_search_test PRIVATE ../include)


SETUP_TARGET_FOR_COVERAGE_LCOV(
    NAME coverage
    EXECUTABLE ctest
)