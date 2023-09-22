#include <gtest/gtest.h>
#include "textReplace.h"

TEST(TextReplaceTest, test1) {
    ASSERT_EQ(textReplace("Hello, World!", 3, 'l', 'X'), "Hello, WorXd!");
}

TEST(TextReplaceTest, test2) {
    ASSERT_EQ(textReplace("abacadaef", 1, 'a', 'X'), "XbXcXdXef");
}

TEST(TextReplaceTest, test3) {
    ASSERT_EQ(textReplace("ChelMedvedoSvin zhivet v peshere", 0, 'e', 'G'), "ChelMedvedoSvin zhivet v peshere");
}

TEST(TextReplaceTest, test4) {
    ASSERT_EQ(textReplace("Respect my authoritah!", 2, 'g', 'X'), "Respect my authoritah!");
}

TEST(TextReplaceTest, test5) {
    ASSERT_EQ(textReplace("Robot Aweeesome-2000", -1, 'o', 'X'), "Robot Aweeesome-2000");
}

TEST(TextReplaceTest, test6) {
    ASSERT_EQ(textReplace("Mississippi", 5, 'i', 'X'), "Mississippi");
}

TEST(TextReplaceTest, test7) {
    ASSERT_EQ(textReplace("", 2, 'X', 'Y'), "");
}

TEST(TextReplaceTest, test8) {
    ASSERT_EQ(textReplace("abcabc", 1, 'a', 'a'), "abcabc");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
