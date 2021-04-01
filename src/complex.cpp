#include "complex.h"
#include <cmath>
#include <iomanip>

Complex::Complex()
{
	Re = 0;
	Im = 0;
}

Complex::Complex(double a, double b)
{
	Re = a;
	Im = b;
}

Complex Complex::operator+=(const Complex &a)
{
	this->Re = Re + a.Re;
	this->Im = Im + a.Im;
	return *this;
}

Complex Complex::operator/=(const Complex &a)
{
	Complex result, z;
	double k;
	if (a.Re == 0 && a.Im == 0)
	{
		cerr << "Division by 0 exception" << endl;
		return *this;
	}
	z.Im = a.Im; // 'a' is const need 'z' to perform a conjugate
	z.Re = a.Re;
	z.complex_conjugate();
	k = square_of_complex_abs(a);
	result.Re = (this->Re * z.Re + this->Im * z.Im * (-1)) / k;
	result.Im = (this->Re * z.Im + z.Re * this->Im) / k;
	return result;
}

Complex Complex::operator+(const Complex &a)
{
	Complex result;
	result.Re = Re + a.Re;
	result.Im = Im + a.Im;
	return result;
}

Complex Complex::operator-(const Complex &a)
{
	Complex result;
	result.Re = Re - a.Re;
	result.Im = Im - a.Im;
	return result;
}

Complex Complex::operator*(const Complex &a)
{
	Complex result;
	result.Re = Re * a.Re + Im * a.Im * (-1);
	result.Im = Re * a.Im + a.Re * Im;
	return result;
}

Complex Complex::operator/(const Complex &a)
{
	Complex result, z;
	double k;
	if (a.Re == 0 && a.Im == 0)
	{
		cerr << "Division by 0 exception" << endl;
		return result;
	}
	z.Im = a.Im; // 'a' is const need 'z' to perform a conjugate
	z.Re = a.Re;
	z.complex_conjugate();
	k = square_of_complex_abs(a);
	result.Re = (Re * z.Re + Im * z.Im * (-1)) / k;
	result.Im = (Re * z.Im + z.Re * Im) / k;
	return result;
}

Complex Complex::operator/(double b)
{
	Complex result;
	if (b == 0)
	{
		cerr << "Division by 0 exception" << endl;
		return result;
	}

	result.Re = Re / b;
	result.Im = Im / b;

	return result;
}

bool operator==(const Complex &a, const Complex &b)
{
	if (abs(a.Re - b.Re) <= MIN_DIFF && abs(a.Im - b.Im) <= MIN_DIFF)
	{
		return true;
	}
	else
		return false;
}

bool operator!=(const Complex &a, const Complex &b)
{
	return (a.Re != b.Re || a.Im != b.Im);
}

istream &check_enter(istream &in, int mode) // 0 mode - "==" 1 mode - "!="
{
	if (mode == 0)
	{
		if (in.peek() == '\n') // lack of ')'
		{
			in.setstate(ios::failbit);
			return in;
		}
	}
	else if (mode == 1)
	{
		if (in.peek() != '\n') // lack of ')'
		{
			in.setstate(ios::failbit);
			return in;
		}
	}
	else
	{
		cerr << "[ERROR]-badly used \"check_enter\" function" << endl;
	}

	return in;
}

istream &check_fail(istream &in)
{
	if (in.fail())
	{
		return in;
	}
	return in;
}

istream &check_char(istream &in, char readed, char wanted)
{
	if (readed != wanted)
	{
		in.setstate(ios::failbit);
		return in;
	}
	return in;
}

istream &operator>>(istream &input, Complex &z) // extended notation
{
	char a, i;
	double number, number2;

	input >> a; // read first bracket
	check_fail(input);
	check_char(input, a, '(');

	input >> i;

	check_enter(input, 0); // if true-> lack of ending bracket
	input >> a;

	check_fail(input);

	if (i == 'i' || (i == '-' && a == 'i')) // (i) (-i)
	{
		z.Re = 0;
		if (i == '-')
			z.Im = -1;
		else
		{
			z.Im = 1;
			input.putback(a); // probably an ')'
		}
		check_enter(input, 0);
		input >> a;
		check_fail(input);
		check_char(input, a, ')');
		check_enter(input, 1); // if true-> extra characters after ending bracket
		z.reset_value(input);  // if failed reset value of "z"
		return input;
	}
	else // if not (i) or (-i) case,put back readed chars
	{
		input.putback(a);
		input.putback(i);
	}

	input >> number;
	check_fail(input);
	check_enter(input, 0);
	input >> i;
	check_fail(input);

	if (i == 'i') // (1,55i),(25i) ... cases
	{
		z.Re = 0;
		z.Im = number;
		check_enter(input, 0);
		input >> a;
		check_fail(input);
		check_char(input, a, ')');
		check_enter(input, 1);
		z.reset_value(input);
		return input;
	}
	else if (i == ')') // (25),(1,333) ... Im part = 0 cases
	{
		check_enter(input, 1);
		z.Re = number;
		z.Im = 0;
		z.reset_value(input);
		return input;
	}
	else if (i == '+' || i == '-') // (2+i) (25+1,555i) ... cases
	{
		input >> a; // checking (2+i) (3-i) cases
		check_fail(input);
		if (a == 'i') // (2+i) (4-i) cases
		{
			z.Re = number;
			if (i == '-')
				z.Im = -1;
			else
				z.Im = 1;
			check_enter(input, 0);
			input >> a;
			check_fail(input);
			check_char(input, a, ')');
			check_enter(input, 1);
			z.reset_value(input);
			return input;
		}
		else
			input.putback(a);

		input >> number2;
		check_fail(input);
		input >> a;

		if (a != 'i')
		{
			input.setstate(ios::failbit);
			z.reset_value(input);
			return input;
		}
		else
		{
			z.Re = number;
			if (i == '-')
				z.Im = (-1) * number2;
			else
				z.Im = number2;
			check_enter(input, 0);
			input >> a;
			check_fail(input);
			check_char(input, a, ')');
			check_enter(input, 1);
			z.reset_value(input);
			return input;
		}
	}
	check_enter(input, 0);
	input >> a;
	check_fail(input);
	check_char(input, a, ')');
	check_enter(input, 1);
	z.reset_value(input);
	return input;
}

void Complex::reset_value(istream &input)
{
	if (input.fail())
	{
		Re = 0;
		Im = 0;
	}
}

ostream &operator<<(ostream &os, const Complex &z)
{
	os << setprecision(3) << fixed; // decimal places 0.000
	if (z.Re == 0 && z.Im == 0)		// (0)
	{
		os << "(0)";
		return os;
	}
	if (z.Re != 0 && z.Im == 0) // (14)...
	{
		os << "(" << z.Re << ")";
		return os;
	}
	if (z.Re == 0 && z.Im != 0) // (12i)...
	{
		if (z.Im != 1 && z.Im != -1)
			os << "(" << z.Im << "i)";
		else if (z.Im == 1)
			os << "(i)";
		else
			os << "(-i)";
		return os;
	}
	if (z.Re != 0 && z.Im > 0) // (12+12i)...
	{
		if (z.Im != 1)
			os << "(" << z.Re << "+" << z.Im << "i)";
		else
			os << "(" << z.Re << "+i)";
		return os;
	}
	if (z.Re != 0 && z.Im < 0) // (12-12i)...
	{
		if (z.Im != -1)
			os << "(" << z.Re << z.Im << "i)";
		else
			os << "(" << z.Re << "-i)";
		return os;
	}
	return os;
}

Complex read_complex(Complex &z)
{
	int j = 0;
	while (j != 3) // set how many tries
	{
		if (cin >> z) // reading went right we can stop the loop
			break;
		if (!(cin >> z)) // reding went wrong,we have to repeat the process
		{
			clean_cin();
		}
		j++;
	}
	return z;
}

void clean_cin()
{
	cout << "Please enter complex number only." << endl; // error message

	cin.clear(); // reset the stream
	cin.ignore(10000, '\n');
}

Complex Complex::complex_conjugate()
{
	Im = Im * (-1);
	return *this;
}

double square_of_complex_abs(const Complex &z)
{
	return (z.Re * z.Re) + (z.Im * z.Im);
}

void Complex::arg()
{
	// atan(1) equals PI/4 so atan(1)*4 equals PI
	double angle;

	if (this->Re > 0)
		angle = atan2(Im, Re);
	if (this->Re < 0)
		angle = atan2(Im, Re) + atan(1) * 4;

	if (this->Im > 0 && this->Re == 0)
		angle = atan(1) * 2;
	if (this->Im < 0 && this->Re == 0)
		angle = -atan(1) * 2;

	if (this->Im == 0 && this->Re == 0)
		cerr << "Arg of " << *this << " is undefined" << endl;
	else
		cout << "Arg of " << *this << " is:" << angle << endl;
}
