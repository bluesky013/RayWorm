cmake_minimum_required(VERSION 3.10)

project(Scene)

include_directories(${RayRoot}/3rd/tinygltf)
include_directories(${RayRoot}/3rd/tinygltf/examples/common/glm)

include_directories(${RayRoot}/main/Common/include)
include_directories(include)
include_directories(src)

set(SceneSrc
    src/RayNode.cpp
    src/RayCamera.cpp
    src/RayShape.cpp
    src/RayBuffer.cpp
    src/RayPrimitive.cpp
    src/RayLoader.cpp
    src/RayMesh.cpp
    src/GltfLoader.cpp
)

set(SceneInc

)

add_library(Scene STATIC
    ${SceneSrc}
)

link_libraries(Scene
    Common
)