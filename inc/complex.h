#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{
public:
	float Re, Im;

	Complex();
	Complex(float a, float b);

	Complex operator+(const Complex &a);
	Complex operator-(const Complex &a);
	Complex operator*(const Complex &a);
	Complex operator/(const Complex &a);
	Complex operator/(float b);

	friend bool operator==(const Complex &a, const Complex &b);
	friend bool operator!=(const Complex &a, const Complex &b);
	friend ostream &operator<<(ostream &os, const Complex &z);
	friend istream &operator>>(istream &in, Complex &c);
};

Complex read_complex(Complex &a); // cin validation
void clean_cin();				  // clean cin

istream &check_enter(istream &in, int mode); // 0 mode - "==" 1 mode - "!="
istream &check_fail(istream &in);
istream &check_char(istream &in, char readed, char wanted);

Complex complex_conjugate(Complex &z);
float square_of_complex_abs(const Complex &z);

#endif //COMPLEX_H