#include <gtest/gtest.h>
#include <RayLoader.h>

using namespace Worm::Asset;

class LoaderTest : public ::testing::Test {
protected:
    LoaderTest() {}
    ~LoaderTest() override {}

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(LoaderTest, GltfTest1) {
    Loader* loader = Loader::loadAsset("scene.gltf");
    EXPECT_NE(loader, nullptr);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}