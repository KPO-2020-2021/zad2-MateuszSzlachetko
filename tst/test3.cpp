#include "gtest/gtest.h"
#include "statistics.h"
#include "complex_equation.h"
// STATISTICS | EQUATION SOLVER

TEST(Statistics, test1)
{
    statistics exam1(2, 3), exam2(2, 5), exam3(10, 12), exam4(20, 30), exam5(0, 0), exam6(-5, 2);

    EXPECT_NE(exam2.end_exam(), exam3.end_exam());
    EXPECT_EQ(exam1.end_exam(), exam4.end_exam());
    EXPECT_EQ(exam5.end_exam(), 0);
    EXPECT_EQ(exam6.end_exam(), 0);
}

TEST(EquationSolver, test1)
{
    Equation eq1(Complex(2, 1), '+', Complex(2, 5)), eq2(Complex(3.333, 1), '+', Complex(5, -5));
    Complex result;

    result = eq1.solve_equation();
    EXPECT_EQ(result, Complex(4, 6));
    EXPECT_NE(result, Complex(4, 128128));
    EXPECT_NE(result, Complex(3.9, 6));

    result = eq2.solve_equation();
    EXPECT_EQ(result, Complex(8.333, -4));
    EXPECT_NE(result, Complex(8.3, -4));
    EXPECT_NE(result, Complex(8.4, -4));
}

TEST(EquationSolver, test2)
{
    Equation eq1(Complex(6, 1), '-', Complex(10, 4)), eq2(Complex(22.1111, 1), '-', Complex(1.111, 0));
    Complex result;

    result = eq1.solve_equation();
    EXPECT_EQ(result, Complex(-4, -3));
    EXPECT_NE(result, Complex(4, 3));
    EXPECT_NE(result, Complex(-4.1, -3));

    result = eq2.solve_equation();
    EXPECT_EQ(result, Complex(21.0001, 1));
    EXPECT_EQ(result, Complex(21, 1));
    EXPECT_NE(result, Complex(21, 0));
}

TEST(EquationSolver, test3)
{
    Equation eq1(Complex(0, 1), '*', Complex(3, 3)), eq2(Complex(3.3333, 1), '*', Complex(3, 1));
    Complex result;

    result = eq1.solve_equation();
    EXPECT_EQ(result, Complex(-3, 3));
    EXPECT_NE(result, Complex(1, 2));
    EXPECT_NE(result, Complex(3, -3));

    result = eq2.solve_equation();
    EXPECT_EQ(result, Complex(9, 6.3333));
    EXPECT_EQ(result, Complex(8.9999, 6.33339));
    EXPECT_NE(result, Complex(8.4, -4));
}

TEST(EquationSolver, test4)
{
    Equation eq1(Complex(2, 1), '/', Complex(13, -4)), eq2(Complex(3.333, 1), '/', Complex(1, 0));
    Complex result;

    result = eq1.solve_equation();
    EXPECT_EQ(result, Complex(0.1189, 0.11351));
    EXPECT_EQ(result, Complex(0.119, 0.11350));
    EXPECT_NE(result, Complex(3.9, 6));

    result = eq2.solve_equation();
    EXPECT_EQ(result, Complex(3.333, 1));
    EXPECT_NE(result, Complex(3, 2));
    EXPECT_NE(result, Complex(3.333, 0.998));
}