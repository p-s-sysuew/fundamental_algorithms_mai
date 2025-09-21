#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void flag_h(int x)
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

void flag_p(int x)
{
    bool f = true;
    double x_05 = pow(x, 0.5);
    for (int d = 2; d <= x_05; d ++)
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


void flag_s(int x)
{
    
    char buf[33];
    char * p = buf + 32;
    int r;
    * p -- = 0;
    while (x)
    {
        r = x % 16;
        if (r > 9) *p-- = r - 10 + 'A';
        else *p-- = r + '0';
        x /= 16;
    }
    p++;
    printf("Число %d в десятичное ситеме равно числу \n\t");
    while(*p)
    {
        printf("%c ", p[0]);
        p++;
        
    }
    printf("\nв шсетнадцатеричной.\n");
}


void flag_e(int x)
{
    
    if (x > 10)
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
    long long sum = 0;
    for (int i = 1; i <= x; i++) sum += i;
    printf("Сумма всех чисел от 1 до %d равна %lld\n", x, sum);
}

void flag_f(int x)
{
    long long f = 1;
    for (int i = 1; i <= x; i++) f *= i;
    printf("Факториал числа %d равен %lld\n", x, f);
}