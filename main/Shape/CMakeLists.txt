cmake_minimum_required(VERSION 3.10)

project(Shape)

include_directories(${RayRoot}/3rd/tinygltf/examples/common/glm)
include_directories(${RayRoot}/main/Common/include)
include_directories(include)
include_directories(src)

set(ShapeSrc
    src/RayShape.cpp
)

set(ShapeInc

)

add_library(Shape STATIC
    ${ShapeSrc}
)

link_libraries(Shape
    Common
)