cmake_minimum_required(VERSION 3.10)

project(CommonTest)

include_directories(${RayRoot}/3rd/googletest/build/include)
include_directories(${RayRoot}/main/Common/include)

link_directories(${RayRoot}/3rd/googletest/build/lib/Debug)
set(GTestLib libgtestd.a)

set(CommonTestSrc
    main.cpp
)

add_executable(CommonTest ${CommonTestSrc}
)

target_link_libraries(CommonTest
    Common
    ${GTestLib}
)