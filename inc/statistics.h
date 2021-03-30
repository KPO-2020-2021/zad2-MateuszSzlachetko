#ifndef STATISTICS_H
#define STATISTICS_H

#include "complex_equation.h"

/*
 * Object of statistics handles values from the exam
 * to sum up the score and tell the user what is his result
 */

class statistics
{
private:
    int wrong_answers;
    int all_questions;

public:
    statistics();
    statistics(int a, int b);
    float end_exam();
};

#endif //STATISTICS_H