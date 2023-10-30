#include <gtest/gtest.h>
#include "../include/figures/hexagon.hpp"

#define INACCURACY 1e-4

TEST(HexagonConstructorTest, ValidData) {
  Point p1(10, 10);
  Point p2(p1.getX() - 2, p1.getY());
  Point p3(p2.getX() - 1, p2.getY() + std::sqrt(3));
  Point p4(p3.getX() + 1, p3.getY() + std::sqrt(3));
  Point p5(p4.getX() + 2, p4.getY());
  Point p6(p5.getX() + 1, p5.getY() - std::sqrt(3));

  EXPECT_NO_THROW(Hexagon(p1, p2, p3, p4, p5, p6));
}

TEST(HexagonConstructorTest, InvalidData) {
  Point p1(10, 10);
  Point p2(p1.getX() - 2, p1.getY());
  Point p3(p2.getX() - 1, p2.getY() + std::sqrt(3));
  Point p4(p3.getX() + 1, p3.getY() + std::sqrt(3));
  Point p5(p4.getX() + 9, p4.getY()); 
  Point p6(p4.getX() + 2, p4.getY());

  EXPECT_THROW(Hexagon(p1, p2, p3, p4, p5, p6), std::invalid_argument);
}

TEST(HexagonGeometricCenterTest, Normal) {
  Point p1(10, 10);
  Point p2(p1.getX() - 2, p1.getY());
  Point p3(p2.getX() - 1, p2.getY() + std::sqrt(3));
  Point p4(p3.getX() + 1, p3.getY() + std::sqrt(3));
  Point p5(p4.getX() + 2, p4.getY());
  Point p6(p5.getX() + 1, p5.getY() - std::sqrt(3));

  Hexagon test(p1, p2, p3, p4, p5, p6);

  Point centre = test.geometricCenter();

  EXPECT_TRUE(centre.getX() - 8.5 < INACCURACY);
  EXPECT_TRUE(centre.getY() - 10 < INACCURACY);
}

TEST(HexagonOperatorDoubleTest, Normal) {
  Point p1(10, 10);
  Point p2(p1.getX() - 2, p1.getY());
  Point p3(p2.getX() - 1, p2.getY() + std::sqrt(3));
  Point p4(p3.getX() + 1, p3.getY() + std::sqrt(3));
  Point p5(p4.getX() + 2, p4.getY());
  Point p6(p5.getX() + 1, p5.getY() - std::sqrt(3));

  Hexagon test(p1, p2, p3, p4, p5, p6);

  double square = static_cast<double>(test);
  EXPECT_TRUE(square - 155.8859 < INACCURACY);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
