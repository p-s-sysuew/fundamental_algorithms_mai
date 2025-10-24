#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void flag_h(int x)
{
    if (x == 0)
    {
        printf("На ноль делить нельзя!\n");
    }
    else
    {
        printf("Числа, от 1 до 100, которые кратны %d:\n", x);
        int count = 0;
        for (int i = 1; i <= 100; i++)
        {
            if (i % x == 0) 
            {
                printf("%d\n", i);
                count++;
            }
        
        }
        if (count == 0) 
            printf("Таких чисел не найдено\n");
    }
    
}

void flag_p(int x)
{
    if (x == 1 || x == 0)
        printf("%d не явялется простым числом\n", x);
    else if (x < 0)
        printf("Отрицательные числа не являются простыми\n");
    else{
    bool f = true;

    for (int d = 2; d * d <= x; d ++)
        if (x % d == 0)
        {
            f = false;
            break;
        }
    if (f)
        printf("%d является простым числом\n", x);
    else
        printf("%d является составным числом\n", x);
    }
    
            
    
}


void flag_s(int x)
{
    printf("Число %d в десятичное ситеме равно числу \n\t", x);
    char buf[33];
    char * p = buf + 32;
    int r;
    * p -- = 0;
    if (x < 0)
    {
        printf("- ");
        x = - x;
    }
        
    if (x == 0)
        printf(" 0 \n");
    while (x)
    {
        r = x % 16;
        if (r > 9) *p-- = r - 10 + 'A';
        else *p-- = r + '0';
        x /= 16;
    }
    p++;
    
    while(*p)
    {
        printf("%c ", p[0]);
        p++;
        
    }
    printf("\nв шестнадцатеричной.\n");
}


void flag_e(const int x)
{
    if (x <= 0)
        printf("Должно быть введено натуральное значение\n");
    else if (x > 10)
        printf("Введённое число не должно превышать 10\n");
    else{
        printf("Таблица степеней от 1 до %d\n\n", x);
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                double ans = pow(i,j);
                if (ans > 0)
                {
                    printf("%ld ^ %ld = %lld\n", i, j, (long long)pow(i, j));
                }
                
            }
            printf("\n\n");
        }
    }
}

void flag_a(int x)
{
    if (x <= 0)
        printf("Должны быть введены натуральные значения\n");
    else if (x > 10000)
        printf("Введено слишком большое значение!");
    else
    {
    long long sum = 0;
    sum = ((1 + x) * x) / 2;
    printf("Сумма всех чисел от 1 до %d равна %lld\n", x, sum);
    }
    
}

void flag_f(int x)
{
    if (x <= 0)
        printf("Должны быть введены положительные значения\n");
    else if (x > 20)
        printf("Не удастся вычислить факториал, т.к. он будет сильно большим числом\n");
    else
    {
    long long f = 1;
    for (int i = 1; i <= x; i++) f *= i;
    printf("Факториал числа %d равен %lld\n", x, f);
    }
    
}