#ifndef EXAM_H
#define EXAM_H

#include "statistics.h"
#include <fstream>

/*
 * Checking difficulty flag set by user,if it does not match with what was
 * expected,function will set easy level of questions by default
 */
string check_difficulty(char *flag[], int arg_counter);

/*
 * Every readed equation expects '\n' after last bracket (to avoid (2+i)-(5i)sdads),
 * so this function reads how many equations were written correctly,sets how many errors occured,
 * to dynamically allocate memory for Equations array,and then the next function can avoid reading
 * last line which is always an '\n' (enter)
 */
int check_lines(string filename, int &errors);

/*
 * Opening a file with equations,then it is trying to read the equation
 * if reading was correct it goes to the next element
 * if an error occured,it skips the line,and sends message to user
 */
Equation *get_equations(string filename, Equation *array, int lines, int errors);

/*
 * Make exam,print equation,ask for answer,if it matches with what was solved
 * from equation,score++,then end exam with end_exam function
 */
void make_exam(Equation *testbase, int lines);

#endif //EXAM_H