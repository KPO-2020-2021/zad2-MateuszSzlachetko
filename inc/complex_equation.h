#ifndef COMPLEX_EQUATION_H
#define COMPLEX_EQUATION_H

#include "complex.h"

/*
 * Equation object is created with 2 complex numbers and an operator which let's us perform
 * with given expression
 */

class Equation
{
public:
    Complex first;
    char op;
    Complex second;

    Equation();
    Equation(Complex a, char oper, Complex b);
    friend ostream &operator<<(ostream &os, const Equation &eq);      // print the equation
    friend istream &operator>>(istream &input, Equation &eq);         // read the equation
    friend bool operator==(const Equation &eq1, const Equation &eq2); // compare equations
    Complex solve_equation();
};
istream &read_first_complex(istream &input, Complex &z); // read the first complex without checking if the last ' ' is '\n'

#endif //COMPLEX_EQUATION_H