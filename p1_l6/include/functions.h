#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

// Нахождение e
double f_a(double x);
double f_b(double x);
double f_c(double x);
double f_d(double x); 

double trap(double (*f)(double), double a, double b, double epsilon);

// Преобразовывает строку в вещественное число
double str_double(char * str);

// Проверяет, явялется ли число вещественным
bool check_double(char * ptr);

#endif