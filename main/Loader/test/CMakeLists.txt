cmake_minimum_required(VERSION 3.10)

project(LoaderTest)

include_directories(${RayRoot}/3rd/googletest/build/include)
include_directories(${RayRoot}/main/Loader/include)

link_directories(${RayRoot}/3rd/googletest/build/lib/Debug)

set(GTestLib libgtestd.a)

set(LoaderTestSrc
    main.cpp
)

add_executable(LoaderTest ${LoaderTestSrc}
)

target_link_libraries(LoaderTest
    Loader
    ${GTestLib}
)