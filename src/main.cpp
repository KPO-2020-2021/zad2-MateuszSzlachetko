#include "complex_equation.h"
using namespace std;

int main()
{
    Complex z;
    // cin >> z;
    // cin.clear();
    //cin.ignore(1000, '\n');
    cout << z;
    // // cin >> z;
    // // cout << z;
    Equation test;

    cin >> test;
    cout << test << endl;
    z = solve_equation(test);
    cout << z << endl;
}