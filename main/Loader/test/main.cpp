

#include <gtest/gtest.h>
#include <Loader.h>

using namespace RayWorm::Loader;

namespace LoaderTest {
class LoaderTest : public ::testing::Test {
protected:
    LoaderTest() {}
    ~LoaderTest() override {}

    void SetUp() override {

    }

    void TearDown() override {

    }

};

TEST_F(LoaderTest, loadAsset) {
    EXPECT_EQ(0, 0);
}

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}