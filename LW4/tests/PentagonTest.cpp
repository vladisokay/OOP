#include <gtest/gtest.h>

#include "../include/figures/pentagon.hpp"
#include "../src/figures/pentagon.cpp"
#include "../src/figures/point.cpp"


#define INACCURACY 1e-4

TEST(PentagonConstructorTest, ValidData) {
  Point<double> p1(0, 1);
  Point<double> p2(0.95106, 0.30902);
  Point<double> p3(0.58779, -0.80902);
  Point<double> p4(-0.58779, -0.80902);
  Point<double> p5(-0.95106, 0.30902);

  EXPECT_NO_THROW(Pentagon(p1, p2, p3, p4, p5));
}

TEST(PentagonConstructorTest, InvalidData) {
  Point<double> p1(10, 10);
  Point<double> p2(p1.getX() - (1 + std::sqrt(2)), p1.getY() + 1);
  Point<double> p3(p2.getX() - 1, p2.getY() + 1 + std::sqrt(2));
  Point<double> p4(p3.getX() + 9 + std::sqrt(2), p3.getY() + 1);
  Point<double> p5(p4.getX() + 1 + std::sqrt(2), p4.getY() + 1);

  EXPECT_THROW(Pentagon(p1, p2, p3, p4, p5), std::invalid_argument);
}

TEST(PentagonGeometricCenterTest, Normal) {
  Point<double> p1(1, 2);
  Point<double> p2(1.95106, 1.30902);
  Point<double> p3(1.58779, 0.19098);
  Point<double> p4(0.41221, 0.19098);
  Point<double> p5(0.04894, 1.30902);

  Pentagon test(p1, p2, p3, p4, p5);

  Point<double> centre = test.geometricCenter();

  EXPECT_TRUE(centre.getX() - 1. < INACCURACY);
  EXPECT_TRUE(centre.getY() - 1. < INACCURACY);
}

TEST(PentagonOperatorDoubleTest, Normal) {
  Point<double> p1(1, 2);
  Point<double> p2(1.95106, 1.30902);
  Point<double> p3(1.58779, 0.19098);
  Point<double> p4(0.41221, 0.19098);
  Point<double> p5(0.04894, 1.30902);

  Pentagon test(p1, p2, p3, p4, p5);

  double square = static_cast<double>(test);
  EXPECT_TRUE(square - 3.86272 < INACCURACY);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
