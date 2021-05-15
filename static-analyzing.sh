#!/bin/bash
mkdir -p build && cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DSANITIZE_ADDRESS=Off -DBUILD_TESTS=Off -DWITH_COVERAGE=Off .. && make -j && cd ..

set -e

echo ""
clang-tidy -p build src/*.cpp include/*.hpp
echo ""
cppcheck --project=build/compile_commands.json --addon=misra.py --enable=all --error-exitcode=1 \
--suppress=missingIncludeSystem --suppress=unusedFunction --suppress=misra-c2012-15.5 --suppress=unmatchedSuppression
echo ""
