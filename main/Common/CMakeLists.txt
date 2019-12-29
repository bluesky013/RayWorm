cmake_minimum_required(VERSION 3.10)

project(Common)

include_directories(include)
include_directories(src)

set(CommonSrc
    src/Test.cpp
)

set(CommonInc

)

add_library(Common STATIC ${CommonSrc})