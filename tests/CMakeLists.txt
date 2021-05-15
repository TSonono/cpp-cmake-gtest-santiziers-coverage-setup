add_subdirectory(googletest)

add_gtest_test(binary_search_test binary_search_test.cpp)
target_link_libraries(binary_search_test binary_search)
target_include_directories(binary_search_test PRIVATE ../include)

if(WITH_COVERAGE)
    setup_target_for_coverage_lcov(
                NAME coverage
                EXECUTABLE ctest
                EXCLUDE "/usr/include/*" "${CMAKE_SOURCE_DIR}/tests/googletest/*")
endif(WITH_COVERAGE)
