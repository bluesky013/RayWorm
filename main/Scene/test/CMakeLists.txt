cmake_minimum_required(VERSION 3.10)

project(SceneTest)

include_directories(${RayRoot}/3rd/googletest/build/include)
include_directories(${RayRoot}/main/Common/include)
include_directories(${RayRoot}/main/Scene/include)
include_directories(${RayRoot}/3rd/tinygltf/examples/common/glm)

link_directories(${RayRoot}/3rd/googletest/build/lib/Debug)

set(GTestLib libgtestd.a)

set(SceneTestSrc
    main.cpp
)

add_executable(SceneTest ${SceneTestSrc}
)

target_link_libraries(SceneTest
    Scene
    Common
    ${GTestLib}
)