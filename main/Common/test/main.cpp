

#include <gtest/gtest.h>
#include "SingletonTest.h"

namespace RayWorm {
namespace Common {

void SingletonTest::testValue(size_t& t)
{
    t = 1;
}

}
}

using namespace RayWorm::Common;
class CommonTest : public ::testing::Test {
protected:
    CommonTest() {}
    ~CommonTest() override {}

    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(CommonTest, SingletonTest1) {
    std::unique_ptr<SingletonTest> singletTest = std::make_unique<SingletonTest>();
    size_t test = 0;
    SingletonTest::getSingleton().testValue(test);
    EXPECT_EQ(test, 1);
}

TEST_F(CommonTest, SingletonTest2) {
    size_t test = 0;
    bool cat = false;
    try {
        SingletonTest::getSingleton().testValue(test);
    } catch (std::runtime_error e) {
        cat  = true;
        EXPECT_EQ(strcmp(e.what(), "Singleton not initialized."), 0);
    }

    EXPECT_EQ(cat, true);
}


TEST_F(CommonTest, SingletonTest3) {
    bool cat = false;
    SingletonTest* t1 = new SingletonTest();
    try {
        SingletonTest* t2 = new SingletonTest();
    } catch (std::runtime_error e) {
        cat  = true;
        EXPECT_EQ(strcmp(e.what(), "Singleton can not instance twice."), 0);
    }
    EXPECT_EQ(cat, true);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}