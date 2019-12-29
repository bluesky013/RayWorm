cmake_minimum_required(VERSION 3.10)

project(Scene)

include_directories(${RayRoot}/3rd/tinygltf)
include_directories(${RayRoot}/3rd/tinygltf/examples/common/glm)

include_directories(${RayRoot}/main/Common/include)
include_directories(include)
include_directories(src)

set(SceneSrc
    src/Node.cpp
    src/Camera.cpp
    src/Shape.cpp
    src/Buffer.cpp
    src/Primitive.cpp
)

set(SceneInc
    include/Camera.h
    include/Geometry.h
    include/Node.h
)

add_library(Scene STATIC
    ${SceneSrc}
)

link_libraries(Scene
    Common
)