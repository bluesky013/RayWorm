cmake_minimum_required(VERSION 3.10)

project(Loader)

include_directories(${RayRoot}/3rd/tinygltf)
include_directories(${RayRoot}/3rd/tinyobjloader)
include_directories(include)
include_directories(src)

set(LoaderSrc
    src/Loader.cpp
    src/GLtfLoader.cpp
)

set(LoaderInc
    include/Loader.h
)

add_library(Loader STATIC
    ${LoaderSrc}
)