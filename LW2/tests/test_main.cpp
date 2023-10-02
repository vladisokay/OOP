#include <gtest/gtest.h>
#include "../include/decimal.h"


TEST(decimalTest, constructAndAssig) {
    Decimal d1;
    EXPECT_EQ(d1.getSize(), 0);
    EXPECT_EQ(d1.toString(), "");

    Decimal d2(3, 6);
    EXPECT_EQ(d2.getSize(), 3);
    EXPECT_EQ(d2.toString(), "666");

    Decimal d3 = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(d3.getSize(), 6);
    EXPECT_EQ(d3.toString(), "123456");

    Decimal d4("6783");
    EXPECT_EQ(d4.getSize(), 4);
    EXPECT_EQ(d4.toString(), "6783");

    Decimal d5(d2);
    EXPECT_EQ(d5.getSize(), 3);
    EXPECT_EQ(d5.toString(), "666");

    Decimal d6;
    d6 = d3;
    EXPECT_EQ(d6.getSize(), 6);
    EXPECT_EQ(d6.toString(), "123456");

}

TEST(decimalTest, arithmeticOperators) {
    Decimal d1("123");
    Decimal d2("456");

    Decimal sum = d1 + d2;
    EXPECT_EQ(sum.getSize(), 3);
    EXPECT_EQ(sum.toString(), "579");

    Decimal diff = d2 - d1;
    EXPECT_EQ(diff.getSize(), 3);
    EXPECT_EQ(diff.toString(), "333");

    try {
        Decimal diff2 = d1 - d2;
        FAIL() << "Expected an exception, but subtraction was successful";
    } catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Result is a negative or zero number");
    }
}

TEST(decimalTest, comparisonOperators) {
    Decimal d1("123");
    Decimal d2("456");
    Decimal d3("123");

    EXPECT_LT(d1, d2);
    EXPECT_FALSE(d2 < d1);
    EXPECT_FALSE(d1 < d3);
    EXPECT_TRUE(d1 < d2);
    EXPECT_TRUE(d3 < d2);

    EXPECT_GT(d2, d1);
    EXPECT_FALSE(d1 > d2);
    EXPECT_FALSE(d1 > d3);
    EXPECT_TRUE(d2 > d3);

    EXPECT_LE(d1, d2);
    EXPECT_LE(d1, d3);
    EXPECT_FALSE(d2 <= d1);

    EXPECT_GE(d2, d1);
    EXPECT_GE(d1, d3);
    EXPECT_FALSE(d1 >= d2);
}

TEST(decimalTest, equalOperators) {
    Decimal d1("123");
    Decimal d2("123");
    Decimal d3("456");

    EXPECT_EQ(d1, d2);
    EXPECT_NE(d1, d3);

    EXPECT_FALSE(d1 != d2);
}


TEST(decimalTest, incrementAndDectement) {
    Decimal d1 = {1, 2, 3};

    ++d1;
    EXPECT_EQ(d1.getSize(), 3);
    EXPECT_EQ(d1.toString(), "124");

    d1++;
    EXPECT_EQ(d1.getSize(), 3);
    EXPECT_EQ(d1.toString(), "125");

    Decimal d2 = --d1;
    EXPECT_EQ(d1.getSize(), 3);
    EXPECT_EQ(d1.toString(), "124");
    EXPECT_EQ(d2.getSize(), 3);
    EXPECT_EQ(d2.toString(), "124");

    d1--;
    EXPECT_EQ(d1.getSize(), 3);
    EXPECT_EQ(d1.toString(), "123");

    Decimal d3 = --d2;
    EXPECT_EQ(d1.getSize(), 3);
    EXPECT_EQ(d1.toString(), "123");
    EXPECT_EQ(d1.getSize(), 3);
    EXPECT_EQ(d1.toString(), "123");
}

TEST(decimalTest, printNum) {
    Decimal d1("12345");
    testing::internal::CaptureStdout();
    d1.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "12345\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}