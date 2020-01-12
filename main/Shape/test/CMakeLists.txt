cmake_minimum_required(VERSION 3.10)

project(ShapeTest)

include_directories(${RayRoot}/3rd/tinygltf/examples/common/glm)
include_directories(${RayRoot}/3rd/googletest/build/include)
include_directories(${RayRoot}/main/Common/include)
include_directories(${RayRoot}/main/Shape/include)

link_directories(${RayRoot}/3rd/googletest/build/lib/Debug)

set(GTestLib libgtestd.a)

set(ShapeTestSrc
    main.cpp
)

add_executable(ShapeTest ${ShapeTestSrc}
)

target_link_libraries(ShapeTest
    Common
    Shape
    ${GTestLib}
)