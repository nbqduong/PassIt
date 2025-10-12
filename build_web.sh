#!/bin/bash

# Create build directory for Emscripten compilation
source ../test/emsdk/emsdk_env.sh
mkdir -p build-wasm
cd build-wasm

# Configure with CMake for Emscripten - FIXED: Use correct relative path from app directory
emcmake cmake .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_EXE_LINKER_FLAGS="-s USE_SDL=2 -s INITIAL_MEMORY=134217728 -s ALLOW_MEMORY_GROWTH=1 -s NO_DISABLE_EXCEPTION_CATCHING -s ASYNCIFY --preload-file ../../assets@/"

# Build the project
emmake make VERBOSE=1 -j$(nproc)