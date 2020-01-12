cmake_minimum_required(VERSION 3.10)

project(SceneDescTest)

include_directories(${RayRoot}/3rd/googletest/build/include)
include_directories(${RayRoot}/main/Common/include)
include_directories(${RayRoot}/main/SceneDesc/include)
include_directories(${RayRoot}/3rd/tinygltf/examples/common/glm)

link_directories(${RayRoot}/3rd/googletest/build/lib/Debug)

set(GTestLib libgtestd.a)

set(SceneDescTestSrc
    main.cpp
)

add_executable(SceneDescTest ${SceneDescTestSrc}
)

target_link_libraries(SceneDescTest
    SceneDesc
    Common
    ${GTestLib}
)