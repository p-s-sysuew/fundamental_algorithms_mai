#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

void menu(void);
void equation(double eps, double a, double b, double c);

int str_int(char * str);
bool check_int(char * str);

bool check_double(char * str);
double str_double(char * str);

void flag_q(double eps, double a, double b, double c);
void flag_m(int a, int b);
void flag_t(double eps, double a, double b, double c);


void triangle(double max_value, double sredn_value, double min_value, double eps) ;




#endif