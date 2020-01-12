cmake_minimum_required(VERSION 3.10)

project(SceneDesc)

include_directories(${RayRoot}/3rd/tinygltf)
include_directories(${RayRoot}/3rd/tinygltf/examples/common/glm)

include_directories(${RayRoot}/main/Common/include)
include_directories(${RayRoot}/main/Asset/include)
include_directories(include)
include_directories(src)

set(SceneDescSrc
    src/RayNode.cpp
    src/RayCamera.cpp
    src/RayMesh.cpp
    src/RayScene.cpp
)

set(SceneDescInc

)

add_library(SceneDesc STATIC
    ${SceneDescSrc}
)

link_libraries(SceneDesc
    Common
)