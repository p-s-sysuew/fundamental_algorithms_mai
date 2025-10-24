#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/functions.h"


int main()
{
    int t; // Колчиство запросов
    long long n, max_number = -1; // Данный введёный номер и максимальный номер из введёных

    printf("Введите количество запросов >> ");
    t = int_scanf(); 
    if (t > 50) {
        printf("Число запросов не должно быть больше 50\n");
        exit(1);
    }
    long long numbers[1000]; // Массив, состоящий из введёных чисел
    
    for (int i = 0; i < t; i++)
    {
        printf("Введите число № %d >> ", i + 1);
        n = int_scanf();
        numbers[i] = n;
        max_number = max(n, max_number);
    }
    printf("\n");

    long long simple_numbers[1000];  // Массив, состоящий из простых чисел
    func(max_number, simple_numbers); // Находим протсые числа и запоняем массив
    

    for (int i = 0; i < t; i++)
    {
        printf("Простое число под номером %lld - это %lld\n", 
            numbers[i], simple_numbers[numbers[i] - 1]);
    }
    printf("\n");

    return 0;
}