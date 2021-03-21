#include "statistics.h"

void end_exam(int wrong_answers, int question_counter)
{
    if (question_counter != 0)
    {
        cout << "\n			Koniec testu" << endl;
        cout << "Ilosc dobrych odpowiedzi: " << question_counter - wrong_answers << endl;
        cout << "Ilosc blednych odpowiedzi: " << wrong_answers << endl;
        cout << "Wynik procentowy poprawnych odpowiedzi :" << 100 * ((float)(question_counter - wrong_answers) / question_counter) << "%" << endl;
    }
    else
    {
        cout << "\n			Test się nie odbył" << endl;
    }
}