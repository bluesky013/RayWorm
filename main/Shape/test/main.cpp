#include <gtest/gtest.h>
#include <RayShape.h>

using namespace Worm::Shape;

class ShapeTest : public ::testing::Test {
protected:
    ShapeTest() {}
    ~ShapeTest() override {}

    void SetUp() override {
    }

    void TearDown() override {
    }
};


TEST_F(ShapeTest, ShapeTest1) {
    Box box1(glm::vec3(-1.f, -1.f, -1.f), glm::vec3(0.f, 0.f, 0.f));
    Box box2(glm::vec3( 0.1f, 0.1f, 0.1f), glm::vec3(1.f, 1.f, 1.f));
    Box box3(glm::vec3(-0.5f,-0.5f,-0.5f), glm::vec3(0.5f, 0.5f, 0.5f));
    Box box4(glm::vec3(-1.f,-1.0f,-0.5f), glm::vec3(1.f, 1.f, 1.f));
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

TEST_F(ShapeTest, RayTest1) {
    Triangle triangle { glm::vec3(-1, 0, 0), glm::vec3(1, 0, 0), glm::vec3(0, 1, 0) };
    SurfaceIntersection interSection;
    bool rst = triangle.calculateRayIntersection(Ray { glm::vec3(0, 0, -1), glm::vec3(0, 0.8, 1) }, interSection);
    EXPECT_EQ(rst, true);
    EXPECT_EQ(interSection.hitPoint, glm::vec3(0, 0.8, 0));
}

TEST_F(ShapeTest, RayTest2) {
    Triangle triangle { glm::vec3(1, 0, 0), glm::vec3(0, 1, 0), glm::vec3(0, 0, 1) };
    SurfaceIntersection interSection;
    bool rst = triangle.calculateRayIntersection(Ray { glm::vec3(0, 0, 0), glm::vec3(1, 1, 1) }, interSection);
    EXPECT_EQ(rst, true);
    EXPECT_EQ(interSection.hitPoint, glm::vec3(1/3.f, 1/3.f, 1/3.f));
}

TEST_F(ShapeTest, RayTest3) {
    Triangle triangle { glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), glm::vec3(1, 1, 0) };
    SurfaceIntersection interSection;
    bool rst = triangle.calculateRayIntersection(Ray { glm::vec3(0, 0, -1), glm::vec3(0.5, 0.5, 1) }, interSection);
    EXPECT_EQ(rst, true);
    EXPECT_EQ(interSection.hitPoint, glm::vec3(0.5f, 0.5f, 0.f));
    EXPECT_EQ(interSection.uv, glm::vec2(0.5f, 0.5f));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}