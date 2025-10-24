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
        
        printf("Должно быть введено допустимое натуральное число! Повторите ввод >> ");
    }
    while (getchar() != '\n');
        
    return number;
}


// Заполняет данный массив простыми числами до определённого номера
int func(const int n, long long * simple_numbers)
{
    int len = 0;
    simple_numbers[0] = 2;
    int len1;
    for (int i = 2; len < n; i++)
        len = simple(i, simple_numbers, len);
}


// Определяет, простое ли число
int simple(int x, long long * simple_numbers, int len)
{
    for (int i = 0; i < len; i++)
        if (x % simple_numbers[i] == 0)
            return len;
    simple_numbers[len] = x;
    len++;
    return len;
}



// Находит максимальное число из двух введёных
long long max(long long a, long long b)
{
    if (a > b) return a;
    else return b;
}