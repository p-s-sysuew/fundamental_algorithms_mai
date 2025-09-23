#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "./include/functions.h"


// Считывает натуральные числа
int int_scanf()
{
    int number;
    while(((scanf("%d", &number)) != 1) || (number < 1))
    {
        while (getchar() != '\n');
        printf("Должно быть введено натуральное число! Повторите ввод >> ");
    }
    while (getchar() != '\n');
        
    return number;
}


// Заполняет данный массив простыми числами до определённого номера
int func(const int n, long long simple_numbers[])
{
    int count = 0;
    for (int i = 1; count < n; i++)
        if (simple(i))
        {
            simple_numbers[count] = i;
            count++;
        }
    
}


// Определяет, простое ли число
bool simple(int x)
{
    double d = pow(x, 0.5);
    for (int i = 2; i <= d; i++)
        if (x % i == 0)
            return false;
    return true;
}



// Находит максимальное число из двух введёных
long long max(long long a, long long b)
{
    if (a > b) return a;
    else return b;
}