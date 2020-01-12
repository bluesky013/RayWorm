cmake_minimum_required(VERSION 3.10)

project(RayBook)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(RayRoot ${CMAKE_SOURCE_DIR})

message("root" ${CMAKE_SOURCE_DIR})

subdirs(main/SceneDesc)
subdirs(main/SceneDesc/test)

subdirs(main/Common)
subdirs(main/Common/test)

subdirs(main/Asset)
subdirs(main/Asset/test)

subdirs(main/Shape)
subdirs(main/Shape/test)