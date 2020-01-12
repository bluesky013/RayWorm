cmake_minimum_required(VERSION 3.10)

project(Asset)

include_directories(${RayRoot}/3rd/tinygltf)
include_directories(${RayRoot}/3rd/tinygltf/examples/common/glm)

include_directories(${RayRoot}/main/Common/include)
include_directories(include)
include_directories(src)

set(AssetSrc
    src/RayLoader.cpp
    src/GltfLoader.cpp
    src/RayBuffer.cpp
    src/RayPrimitive.cpp
)

set(AssetInc

)

add_library(Asset STATIC
    ${AssetSrc}
)

link_libraries(Asset
    Common
)