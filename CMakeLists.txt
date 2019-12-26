cmake_minimum_required(VERSION 3.10)

project(RayBook)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(RayRoot ${CMAKE_SOURCE_DIR})

message("root" ${CMAKE_SOURCE_DIR})

subdirs(main/Loader)
subdirs(main/Loader/test)

subdirs(main/Scene)
subdirs(main/Scene/test)