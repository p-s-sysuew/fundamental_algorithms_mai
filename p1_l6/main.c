#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/functions.h"

int main(int argc, char *argv[]) 
{
    if (argc != 2)
    {
        printf("Программа должна быть вызвана следующим образом:\n");
        printf("    ./my_project (заданая точность)\n");
        exit(1);
    }

    if (!check_double(argv[1]))  {
            printf("Введите корреткное значение!\n");
            exit(2);
    }
    
    double eps = str_double(argv[1]);

    if (eps <= 0) {
        printf("Должно быть введено положительное значение!\n");
        exit(3);
    }
    
    
    double result_a = trap(f_a, 0.0, 1.0, eps);
    printf("f(x) = ln(1+x)/x. Интеграл на отрезке [0, 1] = %.10f\n", result_a);
    
    double result_b = trap(f_b, 0.0, 1.0, eps);
    printf("f(x) = e^(-x²/2). Интеграл на отрезке [0, 1] = %.10f\n", result_b);
    
    double result_c = trap(f_c, 0.0, 1.0, eps);
    printf("f(x) = ln(1/(1-x)). Интеграл на отрезке [0, 1] = %.10f\n", result_c);
    
    double result_d = trap(f_d, 0.0, 1.0, eps);
    printf("f(x) = x^x. Интеграл на отрезке [0, 1] = %.10f\n\n", result_d);
    

    
    return 0;
}