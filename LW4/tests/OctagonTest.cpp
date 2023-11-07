#include <gtest/gtest.h>

#include "../include/figures/octagon.hpp"
#include "../src/figures/octagon.cpp"
#include "../src/figures/point.cpp"

#define INACCURACY 1e-4

TEST(constructor_test, valid_data) {
  Point<double> p1(10, 10);
  Point<double> p2(p1.getX() - (1 + std::sqrt(2)), p1.getY() + 1);
  Point<double> p3(p2.getX() - 1, p2.getY() + 1 + std::sqrt(2));
  Point<double> p4(p3.getX() + 1, p3.getY() + (1 + std::sqrt(2)));
  Point<double> p5(p4.getX() + 1 + std::sqrt(2), p4.getY() + 1);
  Point<double> p6(p5.getX() + 1 + std::sqrt(2), p5.getY() - 1);
  Point<double> p7(p6.getX() + 1, p6.getY() - (1 + std::sqrt(2)));
  Point<double> p8(p7.getX() - 1, p7.getY() - (1 + std::sqrt(2)));

  EXPECT_NO_THROW(Octagon(p1, p2, p3, p4, p5, p6, p7, p8));
}

TEST(constructor_test, invalid_data) {
  Point<double> p1(10, 10);
  Point<double> p2(p1.getX() - (1 + std::sqrt(2)), p1.getY() + 1);
  Point<double> p3(p2.getX() - 1, p2.getY() + 1 + std::sqrt(2));
  Point<double> p4(p3.getX() + 1, p3.getY() + (1 + std::sqrt(2)));
  Point<double> p5(p4.getX() + 9 + std::sqrt(2), p4.getY() + 1);
  Point<double> p6(p5.getX() + 1 + std::sqrt(2), p5.getY() - 1);
  Point<double> p7(p6.getX() + 1, p6.getY() - (1 + std::sqrt(2)));
  Point<double> p8(p7.getX() - 1, p7.getY() - (1 + std::sqrt(2)));

  EXPECT_THROW(Octagon(p1, p2, p3, p4, p5, p6, p7, p8), std::invalid_argument);
}

TEST(calculate_centre_test, normal) {
  Point<double> p1(10, 10);
  Point<double> p2(p1.getX() - (1 + std::sqrt(2)), p1.getY() + 1);
  Point<double> p3(p2.getX() - 1, p2.getY() + 1 + std::sqrt(2));
  Point<double> p4(p3.getX() + 1, p3.getY() + (1 + std::sqrt(2)));
  Point<double> p5(p4.getX() + 1 + std::sqrt(2), p4.getY() + 1);
  Point<double> p6(p5.getX() + 1 + std::sqrt(2), p5.getY() - 1);
  Point<double> p7(p6.getX() + 1, p6.getY() - (1 + std::sqrt(2)));
  Point<double> p8(p7.getX() - 1, p7.getY() - (1 + std::sqrt(2)));

  Octagon test(p1, p2, p3, p4, p5, p6, p7, p8);

  Point<double> centre = test.geometricCenter();

  EXPECT_TRUE(centre.getX() - 10 < INACCURACY);
  EXPECT_TRUE(centre.getY() - 13.4142 < INACCURACY);
}

TEST(operator_double_test, normal) {
  Point<double> p1(10, 10);
  Point<double> p2(p1.getX() - (1 + std::sqrt(2)), p1.getY() + 1);
  Point<double> p3(p2.getX() - 1, p2.getY() + 1 + std::sqrt(2));
  Point<double> p4(p3.getX() + 1, p3.getY() + (1 + std::sqrt(2)));
  Point<double> p5(p4.getX() + 1 + std::sqrt(2), p4.getY() + 1);
  Point<double> p6(p5.getX() + 1 + std::sqrt(2), p5.getY() - 1);
  Point<double> p7(p6.getX() + 1, p6.getY() - (1 + std::sqrt(2)));
  Point<double> p8(p7.getX() - 1, p7.getY() - (1 + std::sqrt(2)));

  Octagon test(p1, p2, p3, p4, p5, p6, p7, p8);

  double square = static_cast<double>(test);
  EXPECT_TRUE(square - 32.9706 < INACCURACY);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}