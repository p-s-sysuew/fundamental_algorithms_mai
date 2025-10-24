#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

// Нахождение e
double func_e_limit(double eps);
double func_e_series(double eps);
double func_e_equation(double eps);

// Нахождение pi
double func_pi_limit(double eps);
double func_pi_series(double eps);
double func_pi_equation(double eps);

// Нахождение ln2
double func_ln2_limit(double eps);
double func_ln2_series(double eps);
double func_ln2_equation(double eps);

// Нахождение aqrt2
double func_sqrt2_limit(double eps);
double func_sqrt2_series(double eps);
double func_sqrt2_equation(double eps);


// Нахождение y
double func_y_limit(double eps);
double func_y_series(double eps, double pi_series);
double func_y_equation(double eps);



// Заполняется список файкториалами чисел
void func_Factorial(long long int * Factorial);

// Выводится С - комбинация
long long combination(long long m, long long k, long long Factorial[]);

// Проверка, является ли число простым
bool is_prime(int n);

#endif