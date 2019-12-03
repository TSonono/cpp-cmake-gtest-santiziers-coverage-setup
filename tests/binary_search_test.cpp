#include <gtest/gtest.h>
#include "binary_search.hpp"

TEST(binarySearchTest, vector1) {
    vector<int> testVector{-55, -3, 0, 2, 33, 44, 999, 1000};
    ASSERT_EQ(binarySearch(testVector, 0), 2);
    ASSERT_EQ(binarySearch(testVector, 1337), -1);
}

TEST(binarySearchTest, vector2) {
    vector<int> testVector{1, 5, 23, 111};
    ASSERT_EQ(binarySearch(testVector, 5), 1);
    ASSERT_EQ(binarySearch(testVector, 23), 2);

    ASSERT_EQ(binarySearch(testVector, 35), -1);
    ASSERT_EQ(binarySearch(testVector, -25), -1);
    ASSERT_EQ(binarySearch(testVector, -1000), -1);
}