#ifndef COMPLEX_H
#define COMPLEX_H
#define MIN_DIFF 0.000105

#include <iostream>
using namespace std;

class Complex
{
public:
	double Re, Im;

	Complex();
	Complex(double a, double b);

	Complex operator+(const Complex &a); // overloaded + operator
	Complex operator-(const Complex &a); // overloaded - operator
	Complex operator*(const Complex &a); // overloaded * operator
	Complex operator/(const Complex &a); // overloaded / operator
	Complex operator/(double b);		 // overloaded / operator
	void reset_value(istream &input);	 // if reading was faulty,reset applied values
	Complex complex_conjugate();		 // change the sign of Im part.

	friend bool operator==(const Complex &a, const Complex &b); // compare 2 complex objects
	friend bool operator!=(const Complex &a, const Complex &b); // compare 2 complex objects
	friend ostream &operator<<(ostream &os, const Complex &z);	// print Complex object
	friend istream &operator>>(istream &in, Complex &c);		// read Complex object
};

Complex read_complex(Complex &a); // cin validation
void clean_cin();				  // clean cin

// Functions to shorten the amount of code for reading a complex object

istream &check_enter(istream &in, int mode); // 0 mode - "==" 1 mode - "!="
istream &check_fail(istream &in);
istream &check_char(istream &in, char readed, char wanted);

double square_of_complex_abs(const Complex &z);

#endif //COMPLEX_H