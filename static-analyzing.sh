#!/bin/sh
REPORT_DIR="html"

CMAKE_FLAGS=""

SCAN_OPT="-enable-checker security.FloatLoopCounter -maxloop 100 \
          -enable-checker core.DivideZero"

# We can put additional checkers here for scan-build

if [ ! -d "Debug" ]; then
    mkdir Debug
fi

cd Debug
scan-build -v -o $REPORT_DIR $SCAN_OPT cmake $CMAKE_FLAGS ..
make clean
scan-build -v -o $REPORT_DIR $SCAN_OPT make -j4
echo ""

cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
cppcheck --project=compile_commands.json --enable=warning --enable=style --enable=performance --enable=portability --enable=information
