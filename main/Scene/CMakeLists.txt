cmake_minimum_required(VERSION 3.10)

project(Scene)

include_directories(${RayRoot}/3rd/tinygltf/examples/common/glm)
include_directories(include)
include_directories(src)

set(SceneSrc
    src/Node.cpp
)

set(SceneInc
    Camera.h
    Geometry.h
    Node.h
)

add_library(Scene STATIC
    ${SceneSrc}
)