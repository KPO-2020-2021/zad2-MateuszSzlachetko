#include "complex.h"
using namespace std;

int main()
{
    Complex z, z1, z2;
    int i = 0, j = 0;
    cout << "test" << endl;
    float k = 0;
    cin >> z1;
    cin >> z2;
    z = z1 / z2;
    cout << z << endl;
    // while (i < 5)
    // {
    //     //z = read_complex(z);
    //     while (j != 3)
    //     {
    //         if (cin >> z)
    //         {
    //             //cout << z;
    //             //cin.ignore(10000, '\n');
    //             break;
    //         }
    //         if (!(cin >> z))
    //         {
    //             cout << "Please enter complex number only." << endl; // error message
    //             cin.clear();                                         // reset the stream
    //             cin.ignore(10000, '\n');
    //             //clean_cin();
    //         }
    //         j++;
    //     }
    //     j = 0;
    //     cout << z;
    //     i++;
    // }
}