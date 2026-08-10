#!/bin/bash

# Usage:
#   ./build.sh        # normal build
#   ./build.sh clean  # remove build directory and rebuild

set -e

if [ "$1" = "clean" ]; then
    echo "Cleaning build directory..."
    rm -rf build
fi

# 1. Create a local build subfolder
mkdir -p build

# 2. Configure and build while explicitly specifying the directories
# -S . means "Source directory is right here"
# -B build means "Output build files into the build folder"
cmake -S . -B build
cmake --build build

./build/calculator
