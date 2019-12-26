#!/bin/bash

echo "*******start building test*******"

cmake --version

mkdir -p build
cd build

cmake ../ -DCMAKE_BUILD_TYPE=Debug -G "Xcode"
cmake --build .