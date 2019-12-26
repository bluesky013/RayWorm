

#include <gtest/gtest.h>
#include <Node.h>

using namespace RayWorm::Scene;

class SceneTest : public ::testing::Test {
protected:
    SceneTest() {}
    ~SceneTest() override {}

    void SetUp() override {

    }

    void TearDown() override {

    }

};

TEST_F(SceneTest, NodeTes1) {
    Node root("test");
    EXPECT_EQ(root.getName(), "test");

    root.setName("root");
    EXPECT_EQ(root.getName(), "root");
}

TEST_F(SceneTest, NodeTes2) {
    Node root("root");
    Node child1("child1");
    Node child2("child2");

    EXPECT_EQ(root.getChildren().size(), size_t(0));
    EXPECT_EQ(child1.getChildren().size(), size_t(0));
    EXPECT_EQ(child2.getChildren().size(), size_t(0));

    root.addChild(child1);
    EXPECT_EQ(child1.getParent()->getName(), "root");
    EXPECT_EQ(root.getChildren().size(), size_t(1));
    EXPECT_EQ(root.getChildren()[0]->getName(), "child1");

    root.addChild(child2);
    EXPECT_EQ(child2.getParent()->getName(), "root");
    EXPECT_EQ(root.getChildren().size(), size_t(2));
    EXPECT_EQ(root.getChildren()[0]->getName(), "child1");
    EXPECT_EQ(root.getChildren()[1]->getName(), "child2");

    root.removeChild(child1);
    EXPECT_EQ(child1.getParent(), nullptr);
    EXPECT_EQ(root.getChildren().size(), size_t(1));
    EXPECT_EQ(root.getChildren()[0]->getName(), "child2");

    root.removeChild(child2);
    EXPECT_EQ(child2.getParent(), nullptr);
    EXPECT_EQ(root.getChildren().size(), size_t(0));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}