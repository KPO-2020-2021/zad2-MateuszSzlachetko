#include "gtest/gtest.h"
#include "complex_equation.h"
// READ/SHOW COMPLEX | READ/SHOW EQUATION

TEST(ReadComplex, test1)
{
    stringstream stream;
    Complex z;

    stream << "(2+2i)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(2, 2));

    stream << "(15.333-2i)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(15.333, -2));

    stream << "(1+1i)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(1, 1));
}

TEST(ReadComplex, test2)
{
    stringstream stream;
    Complex z;

    // EXTENDED NOTATION

    stream << "(0)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(0, 0));

    stream << "(25.33)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(25.33, 0));

    stream << "(-22)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(-22, 0));

    stream << "(i)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(0, 1));

    stream << "(-i)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(0, -1));

    stream << "(15i)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(0, 15));

    stream << "(-22.5512i)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(0, -22.5512));

    stream << "(15-15i)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(15, -15));

    stream << "(1+4i)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(1, 4));

    stream << "(12+i)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(12, 1));

    stream << "(4-i)\n";
    stream >> z;
    EXPECT_EQ(z, Complex(4, -1));
}

TEST(ReadComplex, test3)
{
    stringstream stream;
    Complex z;

    //ERRORS

    stream << "(2+2i)"; // lack of enter pressed after writing Complex number
    stream >> z;
    EXPECT_NE(z, Complex(2, 2));
    stream.clear(); // clear the stream after badly read
    stream.str(std::string());

    stream << "(2+2i"; // lack of ending bracket
    stream >> z;
    EXPECT_NE(z, Complex(2, 2));
    stream.clear();
    stream.str(std::string());

    stream << "2+2i)"; // lack of opening bracket
    stream >> z;
    EXPECT_NE(z, Complex(2, 2));
    stream.clear();
    stream.str(std::string());

    stream << "2+2i"; // lack of brackets
    stream >> z;
    EXPECT_NE(z, Complex(2, 2));
    stream.clear();
    stream.str(std::string());

    stream << "(2+2i)ad"; // something after last bracket
    stream >> z;
    EXPECT_NE(z, Complex(2, 2));
    stream.clear();
    stream.str(std::string());

    stream << "(2+2i) a2d123"; // something after last bracket after space
    stream >> z;
    EXPECT_NE(z, Complex(2, 2));
    stream.clear();
    stream.str(std::string());

    stream << "(2*2i)"; // bad symbol
    stream >> z;
    EXPECT_NE(z, Complex(2, 2));
    stream.clear();
    stream.str(std::string());

    stream << "(2-ai)"; // bad symbol
    stream >> z;
    EXPECT_NE(z, Complex(2, -2));
    stream.clear();
    stream.str(std::string());

    stream << "(2+2ia)"; // bad symbol
    stream >> z;
    EXPECT_NE(z, Complex(2, 2));
    stream.clear();
    stream.str(std::string());

    stream << "(2,05+2i)"; // bad symbol (2.05...)
    stream >> z;
    EXPECT_NE(z, Complex(2.05, 2));
    stream.clear();
    stream.str(std::string());

    stream << "(2i-2)"; // inversed priority
    stream >> z;
    EXPECT_NE(z, Complex(-2, 2));
    stream.clear();
    stream.str(std::string());
}

TEST(ShowComplex, test1)
{
    stringstream stream;
    Complex z(2, 2);
    Complex z1(-23.3336, 15);
    Complex z2(123123, 231);
    Complex z3(78444.12, -233.333);
    Complex z4(0, 0);
    Complex z5(11, 0);
    Complex z6(0, 23);
    Complex z7(1, 1);
    Complex z8(1, -1);
    Complex z9(0, 1);
    Complex z10(0, -1);

    stream << z;
    EXPECT_EQ("(2.000+2.000i)", stream.str());
    stream.str(std::string()); // clear the stream

    stream << z1;
    EXPECT_EQ("(-23.334+15.000i)", stream.str());
    stream.str(std::string());

    stream << z2;
    EXPECT_EQ("(123123.000+231.000i)", stream.str());
    stream.str(std::string());

    stream << z3;
    // std::cout << z3 << std::endl;
    EXPECT_EQ("(78444.120-233.333i)", stream.str());
    stream.str(std::string());

    stream << z4;
    EXPECT_EQ("(0)", stream.str());
    stream.str(std::string());

    stream << z5;
    EXPECT_EQ("(11.000)", stream.str());
    stream.str(std::string());

    stream << z6;
    EXPECT_EQ("(23.000i)", stream.str());
    stream.str(std::string());

    stream << z7;
    EXPECT_EQ("(1.000+i)", stream.str());
    stream.str(std::string());

    stream << z8;
    EXPECT_EQ("(1.000-i)", stream.str());
    stream.str(std::string());

    stream << z9;
    EXPECT_EQ("(i)", stream.str());
    stream.str(std::string());

    stream << z10;
    EXPECT_EQ("(-i)", stream.str());
    stream.str(std::string());
}

TEST(ReadEquation, test1)
{
    stringstream stream;
    Equation eq;
    stream << "(2+i)-(-5i)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(2, 1), '-', Complex(0, -5)));

    stream << "(4+2.333i)+(25)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(4, 2.333), '+', Complex(25, 0)));

    stream << "(5-56i)*(3-i)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(5, -56), '*', Complex(3, -1)));

    stream << "(2+i)/(2)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(2, 1), '/', Complex(2, 0)));

    stream << "(12+i)-(0)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(12, 1), '-', Complex(0, 0)));

    stream << "(12)-(12)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(12, 0), '-', Complex(12, 0)));

    stream << "(4+2.333i)+(4444.44444)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(4, 2.333), '+', Complex(4444.44444, 0)));

    stream << "(i)*(i)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(0, 1), '*', Complex(0, 1)));

    stream << "(2+22.354i)/(-8.999i)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(2, 22.354), '/', Complex(0, -8.999)));

    stream << "(12+1i)-(12i)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(12, 1), '-', Complex(0, 12)));
}

TEST(ReadEquation, test2)
{
    stringstream stream;
    Equation eq;

    // ERRORS

    stream << "(2+i)-(-5i)";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(0, 0), '+', Complex(0, 0))); // expect that nothing was readed
    stream.clear();
    stream.str(std::string());

    stream << "(2+i-(-5i";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(0, 0), '+', Complex(0, 0)));
    stream.clear();
    stream.str(std::string());

    stream << "2+i)-(-5i)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(0, 0), '+', Complex(0, 0)));
    stream.clear();
    stream.str(std::string());

    stream << "(2+i)-(-5i)asdas3";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(0, 0), '+', Complex(0, 0)));
    stream.clear();
    stream.str(std::string());

    stream << "(2+d)-(-5ia)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(0, 0), '+', Complex(0, 0)));
    stream.clear();
    stream.str(std::string());

    stream << "(aa2+i)-(-5i)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(0, 0), '+', Complex(0, 0)));
    stream.clear();
    stream.str(std::string());

    stream << "(aa2+i)-(-5i)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(0, 0), '+', Complex(0, 0)));
    stream.clear();
    stream.str(std::string());

    stream << "(aa2+i)-(-5i)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(0, 0), '+', Complex(0, 0)));
    stream.clear();
    stream.str(std::string());

    stream << "2+i-5i\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(0, 0), '+', Complex(0, 0)));
    stream.clear();
    stream.str(std::string());

    stream << "(2+i)(-5i)\n";
    stream >> eq;
    EXPECT_EQ(eq, Equation(Complex(0, 0), '+', Complex(0, 0)));
    stream.clear();
    stream.str(std::string());
}

TEST(ShowEquation, test1)
{
    stringstream stream;
    Equation eq;
    Equation eq1(Complex(12, 0), '+', Complex(0, 1));
    Equation eq2(Complex(1, 1), '-', Complex(15, 13.577));
    Equation eq3(Complex(0, 212333), '+', Complex(14.6669, 0));
    Equation eq4(Complex(31230, 23.1119), '/', Complex(0, -1));
    Equation eq5(Complex(25, 3), '*', Complex(4, 5));
    Equation eq6(Complex(-5, -5), '+', Complex(-5, -5));
    Equation eq7(Complex(123, -123), '*', Complex(-1, 1));
    Equation eq8(Complex(0, 12), '-', Complex(0, 3));
    Equation eq9(Complex(4.45, 2.2), '/', Complex(-3.1, 33.9999999));

    stream << eq;
    EXPECT_EQ("(0)+(0)", stream.str());
    stream.str(std::string()); // clear the stream

    stream << eq1;
    EXPECT_EQ("(12.000)+(i)", stream.str());
    stream.str(std::string());

    stream << eq2;
    EXPECT_EQ("(1.000+i)-(15.000+13.577i)", stream.str());
    stream.str(std::string());

    stream << eq3;
    EXPECT_EQ("(212333.000i)+(14.667)", stream.str());
    stream.str(std::string());

    stream << eq4;
    EXPECT_EQ("(31230.000+23.112i)/(-i)", stream.str());
    stream.str(std::string());

    stream << eq5;
    EXPECT_EQ("(25.000+3.000i)*(4.000+5.000i)", stream.str());
    stream.str(std::string());

    stream << eq6;
    EXPECT_EQ("(-5.000-5.000i)+(-5.000-5.000i)", stream.str());
    stream.str(std::string());

    stream << eq7;
    EXPECT_EQ("(123.000-123.000i)*(-1.000+i)", stream.str());
    stream.str(std::string());

    stream << eq8;
    EXPECT_EQ("(12.000i)-(3.000i)", stream.str());
    stream.str(std::string());

    stream << eq9;
    EXPECT_EQ("(4.450+2.200i)/(-3.100+34.000i)", stream.str());
    stream.str(std::string());
}