#include "exam.h"

string check_difficulty(char *flag[], int arg_counter)
{
    string filename;
    if (arg_counter < 2)
    {
        cerr << "ERROR-badly chosen difficulty [setting \"latwe\" by default]" << endl;
        filename = "latwe.dat";
    }
    else if (flag[1] == string("latwe"))
        filename = "latwe.dat";
    else if (flag[1] == string("trudne"))
        filename = "trudne.dat";
    else
    {
        cerr << "ERROR-badly chosen difficulty [setting \"latwe\" by default]" << endl;
        filename = "latwe.dat";
    }
    return filename;
}

int check_lines(string filename, int &errors)
{
    ifstream test;
    int goodlines = 0;
    Equation eq;
    test.open(filename);
    if (test.is_open())
    {
        while (!test.eof())
        {
            test >> eq;
            if (test.fail())
            {
                test.clear();
                test.ignore(100, '\n');
                errors++;
            }
            else
            {
                goodlines++;
            }
        }
        test.close();
    }
    else
    {
        cerr << "ERROR-file opening error\n";
    }
    return goodlines;
}

Equation *get_equations(string filename, Equation *array, int lines, int errors)
{
    ifstream test;
    int i = 0, j = 0;
    test.open(filename);

    array = new Equation[lines];

    if (test.is_open())
    {
        while (i < (lines + errors) - 1) // last line is empty because equation expects an enter after the whole line
        {
            test >> array[j];
            if (test.fail())
            {
                cerr << "Nieprawidłowy zapis,równanie zostało pominięte." << endl;
                test.clear();
                test.ignore(100, '\n');
            }
            else
            {
                j++;
            }

            i++;
        }

        test.close();
    }
    else
    {
        cerr << "ERROR-file opening error\n";
    }
    return array;
}

void make_exam(Equation *testbase, int lines)
{
    int i = 0, wrong = 0;
    Complex answer(1, 1), result(0, 0);

    for (i = 0; i < lines; i++)
    {
        cout << "?:nr." << i + 1 << "  Podaj wynik operacji  " << testbase[i] << endl;

        answer = read_complex(answer);
        result = solve_equation(testbase[i]);

        if (result == answer)
            cout << "Poprawna odpowiedz" << endl;
        else if (result != answer)
        {
            cout << "Bledna odpowiedz | Prawidlowym wynikiem jest :" << result << endl;
            wrong++;
        }
    }
    end_exam(wrong, lines);
}