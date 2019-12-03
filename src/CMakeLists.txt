add_library(binary_search binary_search.cpp)
target_include_directories(binary_search PRIVATE ../include)
add_sanitizers(binary_search)