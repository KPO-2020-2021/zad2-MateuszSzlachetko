#include "complex_equation.h"

Equation::Equation()
{
    first.Re = 0;
    first.Im = 0;
    op = '+';
    second.Re = 0;
    second.Im = 0;
}

Equation::Equation(Complex a, char oper, Complex b)
{
    first = a;
    op = oper;
    second = b;
}

ostream &operator<<(ostream &os, const Equation &eq)
{
    os << eq.first << eq.op << eq.second;
    return os;
}

istream &read_first_complex(istream &input, Complex &z)
{
    char a, i;
    float number, number2;

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
        return input;
    }
    else if (i == ')') // (25),(1,333) ... Im part = 0 cases
    {
        z.Re = number;
        z.Im = 0;
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
            return input;
        }
        else
            input.putback(a); //

        input >> number2;
        check_fail(input);
        input >> a;

        if (a != 'i')
        {
            input.setstate(ios::failbit);
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
            return input;
        }
    }
    check_enter(input, 0);
    input >> a;
    check_fail(input);
    check_char(input, a, ')');
    return input;
}

istream &operator>>(istream &input, Equation &eq)
{
    // można to zrobić następująco:
    // input >> eq.first >> eq.op >> eq.second
    // ^ ale >> zespolona; jest zabezpieczone przed brakiem entera po wprowadzeniu ')'
    // więc używam funkcji która zawiera to samo co >> dla complex ale bez sprawdzania '\n'

    Complex z1, z2;
    char a;

    read_first_complex(input, z1);

    input >> a;

    if (input.fail())
        return input;

    if (a != '+' && a != '-' && a != '*' && a != '/')
    {
        input.setstate(ios::failbit);
        return input;
    }

    input >> z2;
    if (input.fail())
        return input;

    eq.op = a;
    eq.first = z1;
    eq.second = z2;

    return input;
}

Complex solve_equation(Equation &eq)
{
    Complex result;

    switch (eq.op)
    {
    case '+':
    {
        result = eq.first + eq.second;
        break;
    }
    case '-':
    {
        result = eq.first - eq.second;
        break;
    }
    case '*':
    {
        result = eq.first * eq.second;
        break;
    }
    case '/':
    {
        result = eq.first / eq.second;
        break;
    }
    default:
        break;
    }

    return result;
}