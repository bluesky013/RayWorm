

#include <gtest/gtest.h>
#include <RayBasic.h>
#include <RayNode.h>
#include <RayShape.h>
#include <RayBuffer.h>
#include <RayPrimitive.h>
#include <RayMesh.h>
#include <RayLoader.h>

using namespace RayWorm::Scene;

class SceneTest : public ::testing::Test {
protected:
    SceneTest() {}
    ~SceneTest() override {}

    void SetUp() override {
        bfBuilder = std::make_unique<BufferBuilder>();
        pmBuilder = std::make_unique<PrimitiveBuilder>();
    }

    void TearDown() override {
    }

    std::unique_ptr<BufferBuilder> bfBuilder;
    std::unique_ptr<PrimitiveBuilder> pmBuilder;
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

TEST_F(SceneTest, ShapeTest1) {
    Box box1 = { glm::vec3(-1.f, -1.f, -1.f), glm::vec3(0.f, 0.f, 0.f) };
    Box box2 = { glm::vec3( 0.1f, 0.1f, 0.1f), glm::vec3(1.f, 1.f, 1.f) };
    Box box3 = { glm::vec3(-0.5f,-0.5f,-0.5f), glm::vec3(0.5f, 0.5f, 0.5f) };
    Box box4 = { glm::vec3(-1.f,-1.0f,-0.5f), glm::vec3(1.f, 1.f, 1.f) };
    glm::vec3 pt1 = { -1.f, -1.f, -1.f };
    glm::vec3 pt2 = {-0.5f,-0.5f,-0.5f };
    glm::vec3 pt3 = { 1.0f, 0.0f, 0.0f };
    glm::vec3 pt4 = {-1.0f, 0.0f, 0.0f };
    glm::vec3 pt5 = { 0.0f, 1.0f, 0.0f };
    glm::vec3 pt6 = { 0.0f,-1.0f, 0.0f };
    glm::vec3 pt7 = { 0.0f, 0.0f, 1.0f };
    glm::vec3 pt8 = { 0.0f, 0.0f,-1.0f };
    glm::vec3 pt9 = { 1.f, 1.f, 1.f };

    EXPECT_EQ(box1.overlaps(box2), false);
    EXPECT_EQ(box1.overlaps(box3), true);
    EXPECT_EQ(box1.overlaps(box4), true);

    EXPECT_EQ(box1.isInside(pt1), true);
    EXPECT_EQ(box1.isInside(pt2), true);
    EXPECT_EQ(box1.isInside(pt3), false);
    EXPECT_EQ(box1.isInside(pt4), true);
    EXPECT_EQ(box1.isInside(pt5), false);
    EXPECT_EQ(box1.isInside(pt6), true);
    EXPECT_EQ(box1.isInside(pt7), false);
    EXPECT_EQ(box1.isInside(pt8), true);
    EXPECT_EQ(box1.isInside(pt9), false);

}

TEST_F(SceneTest, BufferTest1) {
    int p[] = { 1, 2, 3 };
    BufferPtr bf = BufferBuilder::getSingleton().CreateBuffer(sizeof(p));
    bf->setData(reinterpret_cast<unsigned char*>(p));
    const unsigned char* pc = bf->getData();
    const int* pi = reinterpret_cast<const int*>(pc);
    EXPECT_EQ(pi[0], 1);
    EXPECT_EQ(pi[1], 2);
    EXPECT_EQ(pi[2], 3);
}

TEST_F(SceneTest, GltfTest1) {
    Loader* loader = Loader::loadAsset("scene.gltf");
    EXPECT_NE(loader, nullptr);

    Mesh mesh("");
    loader->instantiateMesh("", mesh);

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}