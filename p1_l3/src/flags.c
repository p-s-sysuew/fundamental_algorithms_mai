#include <stdio.h>
#include "./include/functions.h"




void flag_q(double eps, double a, double b, double c)
{
    printf("\nРешения квадратичных уравнений: \n\n");
    equation(eps, a, b, c);
    equation(eps, a, c, b);
    equation(eps, b, a, c);
    equation(eps, b, c, a);
    equation(eps, c, a, b);
    equation(eps, c, b, a);
}

void flag_m(int a, int b)
{
    if (b == 0) {
        printf("Второе число не может быть ранво нулю, т.к тогда \n");
        printf("кратность определить не получится \n");
    }
    else {
        if (a % b == 0)
            printf("%d кратно %d\n", a, b);
        else
            printf("%d не кратно %d\n", a, b);
    }
}


void flag_t(double eps, double a, double b, double c)
{
    printf("составляем треугольник со сторонами %f, %f и %f:\n\n", a, b, c);
    if (a >= b && a >= c)
    {
        if (b + c - a >= eps)
            printf("Можно составить треугольник\n");
        else
            printf("Нельзя составить треугольник\n");
    }
    else if (b >= a && b >= c)
    {
        if (a + c - b >=eps)
            printf("Можно составить треугольник\n");
        else
            printf("Нельзя составить треугольник\n");
    }
    else if (c >= a && c >= b)
    {
        if (a + b - c >= eps)
            printf("Можно составить треугольник\n");
        else
            printf("Нельзя составить треугольник\n");
    }
}