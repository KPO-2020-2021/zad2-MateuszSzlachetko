#ifndef COMPLEX_EQUATION_H
#define COMPLEX_EQUATION_H

#include "complex.h"

class Equation
{
public:
    Complex first;
    char op;
    Complex second;

    Equation();
    Equation(Complex a, char oper, Complex b);
    friend ostream &operator<<(ostream &os, const Equation &eq);
    friend istream &operator>>(istream &input, Equation &eq);
};
istream &read_first_complex(istream &input, Complex &z);
Complex solve_equation(Equation &eq);

#endif //COMPLEX_EQUATION_H