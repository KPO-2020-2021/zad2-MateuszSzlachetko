#include "statistics.h"

statistics::statistics()
{
    this->wrong_answers = 0;
    this->all_questions = 0;
}

statistics::statistics(int a, int b)
{
    this->wrong_answers = a;
    this->all_questions = b;
}

float statistics::end_exam()
{
    float score = 100 * ((float)(this->all_questions - this->wrong_answers) / this->all_questions);

    if (this->all_questions < 0 || this->wrong_answers < 0)
        return 0;

    if (this->all_questions > 0 && (this->all_questions >= this->wrong_answers))
    {

        cout << "\n			Koniec testu" << endl;
        cout << "Ilosc dobrych odpowiedzi: " << this->all_questions - this->wrong_answers << endl;
        cout << "Ilosc blednych odpowiedzi: " << this->wrong_answers << endl;
        cout << "Wynik procentowy poprawnych odpowiedzi :" << score << "%" << endl;
    }
    else
    {
        cout << "\n			Test się nie odbył" << endl;
        return 0;
    }
    return score;
}