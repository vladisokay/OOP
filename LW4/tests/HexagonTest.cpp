#include <gtest/gtest.h>

#include "../include/figures/hexagon.hpp"
#include "../src/figures/hexagon.cpp"
#include "../src/figures/point.cpp"

#define INACCURACY 1e-1

TEST(HexagonConstructorTest, ValidData) {
  Point<double> p1(1, 4);
  Point<double> p2(-3, 0);
  Point<double> p3(std::sqrt(3), 3 - std::sqrt(3));
  Point<double> p4(-std::sqrt(3), 3 + std::sqrt(3));
  Point<double> p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
  Point<double> p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

  EXPECT_NO_THROW(Hexagon(p1, p2, p3, p4, p5, p6));
}

TEST(HexagonConstructorTest, InvalidData) {
  Point<double> p1(1, 8);
  Point<double> p2(-3, 0);
  Point<double> p3(std::sqrt(3), 3 - std::sqrt(3));
  Point<double> p4(-std::sqrt(3), 3 + std::sqrt(3));
  Point<double> p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
  Point<double> p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

  EXPECT_THROW(Hexagon(p1, p2, p3, p4, p5, p6), std::invalid_argument);
}

TEST(HexagonGeometricCenterTest, Normal) {
  Point<double> p1(1, 4);
  Point<double> p2(-3, 0);
  Point<double> p3(std::sqrt(3), 3 - std::sqrt(3));
  Point<double> p4(-std::sqrt(3), 3 + std::sqrt(3));
  Point<double> p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
  Point<double> p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

  Hexagon test(p1, p2, p3, p4, p5, p6);

  Point<double> centre = test.geometricCenter();

  EXPECT_TRUE(centre.getX() - 1 < INACCURACY);
  EXPECT_TRUE(centre.getY() - 2 < INACCURACY);
}

TEST(HexagonOperatorDoubleTest, Normal) {
  Point<double> p1(1, 4);
  Point<double> p2(-3, 0);
  Point<double> p3(std::sqrt(3), 3 - std::sqrt(3));
  Point<double> p4(-std::sqrt(3), 3 + std::sqrt(3));
  Point<double> p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
  Point<double> p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

  Hexagon test(p1, p2, p3, p4, p5, p6);

  double square = static_cast<double>(test);
  EXPECT_TRUE(square - 83.1 < INACCURACY);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
