add_library(binary_search binary_search.cpp)
target_include_directories(binary_search PRIVATE ../include)
add_sanitizers(binary_search)
target_compile_options(binary_search PRIVATE -Wall -Wextra -Werror -Wpedantic -Wshadow -Wcast-qual)