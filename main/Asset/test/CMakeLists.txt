cmake_minimum_required(VERSION 3.10)

project(AssetTest)

include_directories(${RayRoot}/3rd/googletest/build/include)
include_directories(${RayRoot}/main/Common/include)
include_directories(${RayRoot}/main/Asset/include)

link_directories(${RayRoot}/3rd/googletest/build/lib/Debug)

set(GTestLib libgtestd.a)

set(AssetTestSrc
    main.cpp
)

add_executable(AssetTest ${AssetTestSrc}
)

target_link_libraries(AssetTest
    Common
    Asset
    ${GTestLib}
)