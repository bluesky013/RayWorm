#!/bin/bash

echo "*******start building Gooletest*******"

cmake --version

Root=$(pwd)
GTest=${Root}/3rd/googletest

echo "current dir: ---${Root}"
echo "gtest   dir: ---${GTest}"

mkdir -p ${GTest}/build
cd ${GTest}/build

cmake ../ -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=${GTest}/build -G "Xcode"
cmake --build . --target install --config "Debug"
