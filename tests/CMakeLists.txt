add_subdirectory(googletest)

# add_gtest_test(TARGET_TEST TEST_FILE.cpp)
# target_link_libraries(TARGET_TEST TARGET)
# target_include_directories(TARGET_TEST PRIVATE ../include)

if(WITH_COVERAGE)
    setup_target_for_coverage_lcov(
                NAME coverage
                EXECUTABLE ctest
                EXCLUDE "/usr/include/*" "${CMAKE_SOURCE_DIR}/tests/googletest/*")
endif(WITH_COVERAGE)
