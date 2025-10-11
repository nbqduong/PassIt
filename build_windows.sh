#!/bin/bash

# Create build directory for Windows cross-compilation
apt update
apt install mingw-w64
apt install build-essential

# download Cmake
CMAKE_VERSION=3.22
wget "https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-linux-x86_64.sh" -O cmake_installer.sh
chmod +x cmake_installer.sh
sudo ./cmake_installer.sh --skip-license --prefix=/usr/local
rm cmake_installer.sh

mkdir -p build-windows
cd build-windows

# Configure with CMake for MinGW cross-compilation
cmake .. \
    -DCMAKE_SYSTEM_NAME=Windows \
    -DCMAKE_C_COMPILER=x86_64-w64-mingw32-gcc \
    -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ \
    -DCMAKE_RC_COMPILER=x86_64-w64-mingw32-windres \
    -DCMAKE_FIND_ROOT_PATH=/usr/x86_64-w64-mingw32 \
    -DCMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER \
    -DCMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY \
    -DCMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY \
    -DCMAKE_BUILD_TYPE=Release

# Build the project
make VERBOSE=1 -j$(nproc)
