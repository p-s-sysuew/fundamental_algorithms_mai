#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "./include/functions.h"


// Выводит инструкцию по работе с программой
void menu(void)
{
    printf(
        "Программа распознает следующие флаги:\n\n"
        
        "   -q первый параметр (вещественное число) задаёт точность сравнения\n"
        "вещественных чисел (эпсилон), оставшиеся три (вещественные числа)\n"
        "являются коэффициентами квадратного уравнения; необходимо вывести в\n"
        "консоль решения этого уравнения при всевозможных уникальных\n"
        "перестановках значений коэффициентов при степенях переменной;\n\n"

        "   -m необходимо задать два ненулевых целых числа, после чего определить,\n"
        "кратно ли первое число второму;\n\n"

        "   -t первый параметр (вещественное число) задаёт точность сравнения\n"
        "вещественных чисел (эпсилон); необходимо проверить, могут ли\n"
        "оставшиеся три (вещественные числа) параметра являться длинами сторон\n"
        "прямоугольного треугольника\n\n");
}


// Проверяет, явялется ли число вещественным
bool check_double(char * ptr)
{
    if (strlen(ptr) > 9)
    {
        printf("Введено сильно больше значение\n");
        return false;
    }
    const char * str = ptr;
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


// Проверяет, явялется ли число целым
bool check_int(char * str)
{
    if (strlen(str) > 9)
    {
        printf("Введено сильно больше значение\n");
        return false;
    }
    if (str[0] == '-') str++;

    while(* str)
    {
        if (!isdigit(str[0])) return false;
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


// Преобразовыет строку в целое число
int str_int(char * str)
{
    int minus = 1;
    int res = 0;
    if (str[0] == '-')
    {
        minus = -1;
        str++;
    }
    while (*str)
    {
        int c = str[0] - '0';
        res = res * 10 + c;
        str++;
    }
    return res * minus;
}


void equation(double eps, double a, double b, double c)
{
    printf("С помощью коффициентов %f, %f и %f составлено уравнение:\n", a, b, c);
    if (a - 0.0 <= eps)
    {
        if (b - 0.0 <= eps) {
            if (c - 0.0 > eps) {
                printf("Уравнение не имеет решения\n\n");
            }
            else {
                printf("Уравнение имеет бесконечное число решений\n\n");
            }    
        }

        else {
            printf("Это линейное уравнение вида %f * x + %f = 0\n", b, c);
            if (-c / b - 0.0 <= eps) {
                printf("Его решение: x = %f\n\n", 0.0);
            }
            else {
                printf("Его решение: x = %f\n\n", -c / b);
            }
            
        }
        
    }
    else{
        printf("Это квадратное уравнение вида %f * x^2 +  %f * x + %f = 0\n", a, b, c);
        float D = b * b - 4 * a * c;
        if (D < 0)
            printf("Уравнение не имеет решений\n\n");
        else if(D - 0.0 <= eps)
            if (-b / (2 * a) - 0.0 <= eps) {
                printf("Его решение: x = %f\n\n", 0.0);
            }
            else {
                printf("Его решение: x = %f\n\n", -b / (2 * a));
            }
            
        else {
        double d = pow(D, 0.5);
        double x1 = (-b - d) / (2 * a);
        double x2 = (-b + d) / (2 * a);
        printf("Его решение: x1 = %f, x2 = %f\n\n", x1, x2);
        }

    }
}



void triangle(double max_value, double sredn_value, double min_value, double eps) 
{
    if (min_value + sredn_value - max_value >= eps)
    {
            printf("Можно составить треугольник\n");
            if (fabs(min_value * min_value + sredn_value * sredn_value - max_value * max_value) <= eps)
                printf("Можно составить также прямоугольный треугольник\n");
            else
                printf("Нельзя составить прямоугольный треугольник\n");
    }
    else
            printf("Нельзя составить треугольник\n");
}




