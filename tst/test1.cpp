#include "gtest/gtest.h"
#include "complex.h"
// SUBTRACTION | ADDITION | MULTIPLICATION | DIVISION

TEST(Subtraction, test1)
{
    Complex c1(15.55, 13);
    Complex c2(0.1, 3333);
    EXPECT_NE(c1 - c2, Complex(0, 0));
    EXPECT_NE(c1 - c2, Complex(1.22225, 2));
    EXPECT_NE(c1 - c2, Complex(34, -4));
    EXPECT_NE(c1 - c2, Complex(15.45, 3320));

    EXPECT_EQ(c1 - c2, Complex(15.45, -3320));
}

TEST(Subtraction, test2)
{
    Complex c1(3, 5);
    Complex c2(0, 3);
    EXPECT_NE(c1 - c2, Complex(0, 0));
    EXPECT_NE(c1 - c2, Complex(1.5, 2));
    EXPECT_NE(c1 - c2, Complex(3, -4));
    EXPECT_NE(c1 - c2, Complex(1, 1));

    EXPECT_EQ(c1 - c2, Complex(3, 2));
    EXPECT_EQ(c1 - c2, Complex(2.9999, 2));
}

TEST(Subtraction, test3)
{
    Complex c1(0, 0);
    Complex c2(0, 0);
    EXPECT_EQ(c1 - c2, Complex(0, 0));
    EXPECT_EQ(c1 - c2, Complex(0.0001, 0.0001));

    EXPECT_NE(c1 - c2, Complex(0.00011, 0));
}

TEST(Addition, test1)
{
    Complex c1(25, -12);
    Complex c2(3, 4);
    EXPECT_NE(c1 + c2, Complex(0, 0));
    EXPECT_NE(c1 + c2, Complex(27, -9));
    EXPECT_NE(c1 + c2, Complex(34, -4));

    EXPECT_EQ(c1 + c2, Complex(27.9999, -7.9999));
    EXPECT_EQ(c1 + c2, Complex(28, -8));
}

TEST(Addition, test2)
{
    Complex c1(15, 5);
    Complex c2(1.222, 3);
    EXPECT_EQ(c1 + c2, Complex(16.222, 8));
    EXPECT_EQ(c1 + c2, Complex(16.2221, 8.0001));

    EXPECT_NE(c1 + c2, Complex(16.22212, 8.0002));
}

TEST(Addition, test3)
{
    Complex c1(0, 0);
    Complex c2(0, 0);
    Complex c3(0.00001, 0);
    Complex c4(0.00009, 0);
    EXPECT_EQ(c1 + c2, Complex(0, 0));
    EXPECT_EQ(c1 + c2, Complex(0.0001, 0.0001));
    EXPECT_EQ(c3 + c4, Complex(0.00001, 0));

    EXPECT_NE(c1 + c2, Complex(0.00011, 0));
}

TEST(Multiplication, test1)
{
    Complex c1(2, 5);
    Complex c2(1, 2);
    Complex c3(1, 0);

    EXPECT_EQ(c1 * c2, Complex(-8, 9));
    EXPECT_EQ(c1 * c3, Complex(2, 5));

    EXPECT_NE(c1 * c2, Complex(0, 0));
    EXPECT_NE(c1 * c2, Complex(27, -9));
    EXPECT_NE(c1 * c2, Complex(34, -4));
}

TEST(Multiplication, test2)
{
    Complex c1(1, 2);
    Complex c2(13.333, 3);
    Complex c3(2, 0);
    EXPECT_EQ(c1 * c2, Complex(7.333, 29.666));
    EXPECT_EQ(c1 * c2, Complex(7.3331, 29.66599));
    EXPECT_EQ(c1 * c3, Complex(2, 4));
    EXPECT_EQ(c2 * c3, Complex(26.666, 6));

    EXPECT_NE(c1 * c2, Complex(16.22212, 8.0002));
}

TEST(Multiplication, test3)
{
    Complex c1(0, 0);
    Complex c2(1, 0);
    EXPECT_EQ(c1 * c2, Complex(0, 0));

    EXPECT_NE(c1 * c2, Complex(0.0001, 0.0001));
    EXPECT_NE(c1 * c2, Complex(0.00011, 0));
}

TEST(Division, test1)
{
    Complex c1(5, 5);
    Complex c2(1, 1);
    Complex c3(2, 0);
    double a = 2.4, b = 5;

    EXPECT_EQ(c1 / c2, Complex(5, 0));
    EXPECT_EQ(c1 / c3, Complex(2.5, 2.5));
    EXPECT_EQ(c1 / a, Complex(2.0833, 2.0833));
    EXPECT_EQ(c1 / a, Complex(2.0833, 2.0833));
    EXPECT_EQ(c1 / a, Complex(2.08334, 2.0834));
    EXPECT_EQ(c1 / a, Complex(2.08332, 2.0834));
    EXPECT_EQ(c1 / a, Complex(2.08331, 2.0834));
    EXPECT_EQ(c1 / b, Complex(1, 1));

    EXPECT_NE(c1 / c2, Complex(0, 0));
    EXPECT_NE(c1 / c2, Complex(1333, -9));
    EXPECT_NE(c1 / c2, Complex(34, -4));
}

TEST(Division, test2)
{
    Complex c1(1, 1);
    Complex c2(3, 3);
    Complex c3(3, 0);

    EXPECT_EQ(c1 / c2, Complex(0.3333, 0));
    EXPECT_EQ(c1 / c2, Complex(0.33331, 0));
    EXPECT_EQ(c1 / c2, Complex(0.3332333333333333333, 0));
    EXPECT_EQ(c1 / c3, Complex(0.3333, 0.3333));
}

TEST(Division, test3)
{
    Complex c1(0, 0);
    Complex c2(0, 0);
    double a = 0;
    std::cout << std::endl;
    EXPECT_EQ(c1 / c2, Complex(0, 0));
    EXPECT_EQ(c1 / a, Complex(0, 0));
    std::cout << std::endl;
}