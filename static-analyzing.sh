#!/bin/bash
mkdir -p build && cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .. && make -j && cd ..

echo ""
cppcheck --project=build/compile_commands.json --addon=misra.py --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction
echo ""
clang-tidy -p build src/*.cpp include/*.hpp
echo ""
