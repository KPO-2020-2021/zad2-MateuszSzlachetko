#include "gtest/gtest.h"
#include "complex.h"

// MODIFICATIONS

TEST(SumModified, test1)
{
    Complex c1(25, -12);
    Complex c2(3, 4);
    EXPECT_NE(c1 += c2, Complex(0, 0));
    c1.Re = 25;
    c1.Im = -12;
    EXPECT_NE(c1 += c2, Complex(27, -9));
    c1.Re = 25;
    c1.Im = -12;
    EXPECT_NE(c1 += c2, Complex(34, -4));
    c1.Re = 25;
    c1.Im = -12;

    EXPECT_EQ(c1 += c2, Complex(27.9999, -7.9999));
    c1.Re = 25;
    c1.Im = -12;
    EXPECT_EQ(c1 += c2, Complex(28, -8));
}

TEST(SumModified, test2)
{
    Complex c1(15, 5);
    Complex c2(1.222, 3);
    EXPECT_EQ(c1 += c2, Complex(16.222, 8));
    c1.Re = 15;
    c1.Im = 5;
    EXPECT_EQ(c1 += c2, Complex(16.2221, 8.0001));
    c1.Re = 15;
    c1.Im = 5;

    EXPECT_NE(c1 += c2, Complex(16.22212, 8.0002));
}

TEST(SumModified, test3)
{
    Complex c1(0, 0);
    Complex c2(0, 0);
    Complex c3(0.00001, 0);
    Complex c4(0.00009, 0);
    EXPECT_EQ(c1 += c2, Complex(0, 0));
    c1.Re = 0;
    c1.Im = 0;
    EXPECT_EQ(c1 += c2, Complex(0.0001, 0.0001));
    c1.Re = 0;
    c1.Im = 0;
    EXPECT_EQ(c3 += c4, Complex(0.00001, 0));
    c3.Re = 0.00001;
    c3.Im = 0;

    EXPECT_NE(c1 += c2, Complex(0.00011, 0));
}

TEST(DivisionModified, test1)
{
    Complex c1(5, 5);
    Complex c2(1, 1);
    Complex c3(2, 0);

    EXPECT_EQ(c1 /= c2, Complex(5, 0));
    c1.Re = 5;
    c1.Im = 5;
    EXPECT_EQ(c1 /= c3, Complex(2.5, 2.5));
    c1.Re = 5;
    c1.Im = 5;

    EXPECT_NE(c1 /= c2, Complex(0, 0));
    c1.Re = 5;
    c1.Im = 5;
    EXPECT_NE(c1 /= c2, Complex(1333, -9));
    c1.Re = 5;
    c1.Im = 5;
    EXPECT_NE(c1 /= c2, Complex(34, -4));
    c1.Re = 5;
    c1.Im = 5;
}

TEST(DivisionModified, test2)
{
    Complex c1(1, 1);
    Complex c2(3, 3);
    Complex c3(3, 0);

    EXPECT_EQ(c1 /= c2, Complex(0.3333, 0));
    c1.Re = 1;
    c1.Im = 1;
    EXPECT_EQ(c1 /= c2, Complex(0.33331, 0));
    c1.Re = 1;
    c1.Im = 1;
    EXPECT_EQ(c1 /= c2, Complex(0.3332333333333333333, 0));
    c1.Re = 1;
    c1.Im = 1;
    EXPECT_EQ(c1 /= c3, Complex(0.3333, 0.3333));
    c1.Re = 1;
    c1.Im = 1;
}

TEST(DivisionModified, test3)
{
    Complex c1(0, 0);
    Complex c2(0, 0);

    std::cout << std::endl;
    EXPECT_EQ(c1 /= c2, Complex(0, 0));
    c1.Re = 0;
    c1.Im = 0;
    std::cout << std::endl;
}

TEST(argComplex, test1)
{
    Complex c(0, 0);
    Complex c1(12, 5);
    Complex c2(2, -5);
    Complex c3(0, 5);
    Complex c4(1, 0);

    stringstream stream;

    testing::internal::CaptureStderr();
    c.arg();
    std::string output = testing::internal::GetCapturedStderr();
    stream << "Arg of (0) is undefined\n";
    EXPECT_EQ(output, stream.str());
    stream.str(std::string());

    testing::internal::CaptureStdout();
    c1.arg();
    output = testing::internal::GetCapturedStdout();
    stream << "Arg of (12.000+5.000i) is:0.395\n";
    EXPECT_EQ(output, stream.str());
    stream.str(std::string());

    testing::internal::CaptureStdout();
    c2.arg();
    output = testing::internal::GetCapturedStdout();
    stream << "Arg of (2.000-5.000i) is:-1.190\n";
    EXPECT_EQ(output, stream.str());
    stream.str(std::string());

    testing::internal::CaptureStdout();
    c3.arg();
    output = testing::internal::GetCapturedStdout();
    stream << "Arg of (5.000i) is:1.571\n";
    EXPECT_EQ(output, stream.str());
    stream.str(std::string());

    testing::internal::CaptureStdout();
    c4.arg();
    output = testing::internal::GetCapturedStdout();
    stream << "Arg of (1.000) is:0.000\n";
    EXPECT_EQ(output, stream.str());
    stream.str(std::string());
}