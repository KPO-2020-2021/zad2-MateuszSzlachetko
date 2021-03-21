#include "exam.h"

using namespace std;

int main(int argc, char *argv[])
{

    Equation *testbase = NULL;
    int lines = 0, errors = 0;
    string filename;

    filename = check_difficulty(argv, argc);

    lines = check_lines(filename, errors);

    testbase = get_equations(filename, testbase, lines, errors);

    cout << endl;

    make_exam(testbase, lines);

    delete[] testbase;
}
