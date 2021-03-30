#include "gtest/gtest.h"
#include "complex.h"
// EQUALITY | COMPLEX CONJUGATE | SQUARE OF COMPLEX ABS

TEST(Equality, test1)
{
    EXPECT_EQ(Complex(2.25, 1.0001), Complex(2.25, 1));
    EXPECT_EQ(Complex(1, 1), Complex(1, 1));
    EXPECT_EQ(Complex(1, 1.9999), Complex(1, 2));
    EXPECT_EQ(Complex(2929.1123333, 1), Complex(2929.1123444, 1));
    EXPECT_EQ(Complex(5.5555, 4.2), Complex(5.5556, 4.2001));

    EXPECT_NE(Complex(0, 1), Complex(1, 1));
    EXPECT_NE(Complex(1.00011, 1), Complex(1, 1));
}

TEST(ComplexConjugate, test1)
{
    Complex c1(2, -2), c2(1, 5), c3(0, 0);
    c1.complex_conjugate();
    c2.complex_conjugate();
    c3.complex_conjugate();

    EXPECT_EQ(c1, Complex(2, 2));
    EXPECT_NE(c1, Complex(2, -2));
    EXPECT_EQ(c2, Complex(1, -5));
    EXPECT_NE(c2, Complex(1, 5));
    EXPECT_EQ(c3, Complex(0, 0));
    EXPECT_NE(c3, Complex(1, 1));
}

TEST(Square_of_complex_abs, test1)
{
    Complex c1(2, -2), c2(1, 5), c3(0, 0);
    double a, b, c;
    a = square_of_complex_abs(c1);
    b = square_of_complex_abs(c2);
    c = square_of_complex_abs(c3);
    EXPECT_EQ(a, 8);
    EXPECT_EQ(b, 26);
    EXPECT_EQ(c, 0);
}