#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Функции для вычисления подынтегральных выражений
double f_a(double x) {
    if (fabs(x) < 1e-15) return 1.0;
    return log(1.0 + x) / x;
}

double f_b(double x) {
    return exp(-x * x / 2.0);
}

double f_c(double x) {
    if (fabs(x - 1.0) < 1e-15) return 0.0;
    return -log(1.0 - x);
}

double f_d(double x) {
    if (fabs(x) < 1e-15) return 1.0;
    return exp(x * log(x));
}


double trap(double (*f)(double), double a, double b, double epsilon) {
    int n = 2; // начальное количество разбиений
    double h = (b - a) / n;
    
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    double prev_integral = sum * h;
    
    double current_integral;
    do {
        n *= 2;
        h = (b - a) / n;
        
        sum = 0.5 * (f(a) + f(b));
        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            sum += f(x);
        }
        
        current_integral = sum * h;
        
        if (fabs(current_integral - prev_integral) < epsilon) {
            break;
        }
        
        prev_integral = current_integral;
    } while (n < 1000000);
    
    return current_integral;
}



// Проверяет, явялется ли число вещественным
bool check_double(char * ptr)
{
    const char * str = ptr;
    if (strlen(str) > 16)
    {
        printf("Введено сильно больше значение\n");
        return false;
    }
    if (str[0] == '-') str++;
    int count = 0;
    while(* str)
    {
        if (str[0] == '.')
        {
            count++;
            if (count == 2) return false;
        }
        else if (!isdigit(str[0])) return false;
        str++;
    }
    return true;
}

// Преобразовывает строку в вещественное число
double str_double(char * str)
{
    int len = strlen(str);
    bool point_flag = false;
    int point = 0;
    double res = 0;
    int minus = 1;
    if (str[0] == '-')
    {
        minus = -1;
        str++;
        len--;
    }
    while (*str)
    {   
        if (str[0] != '.')
        {
            if (!point_flag)
                point++;
            int c = str[0] - '0';
            res = res * 10.0 + (double)c;
        }
        else 
            point_flag = true;   
        str++;
    }
    len = len - point - 1;
    if (point_flag)
        res = res /  pow(10, len);

    
    return res * minus;
}