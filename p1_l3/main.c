#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/functions.h"


int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        printf("Программа должна быть вызвана следующим образом:\n");
        printf("    ./my_project (флаг) (остлаьные значения)");
        menu();
        exit(1);
    }

    char * flag = argv[1];

    if (strcmp("-q", flag) == 0)
    {
        char * str_eps, * str_a, * str_b, * str_c;
        if (argc != 6)
        {
            printf("Должно быть введено 4 вещественных значения!\n");
            exit(1);
        }

        str_eps = argv[2]; str_a = argv[3]; str_b = argv[4]; str_c = argv[5];

        if (!check_double(str_eps) 
        ||  !check_double(str_a) 
        || !check_double(str_b) 
        || !check_double(str_c))
        {
            printf("Введёные числа должны быть вещественными!\n");
            exit(2);
        }

        double eps = str_double(str_eps);
        double a = str_double(str_a);
        double b = str_double(str_b);
        double c = str_double(str_c);

        flag_q(eps, a, b, c);      
    } 
    else if (strcmp("-m", flag) == 0)
    {
        char * str_a, * str_b;
        if (argc != 4)
        {
            printf("Должно быть введено 2 целых значения!\n");
            exit(3);
        }
        if (!check_int(str_a) 
        ||  !check_int(str_b))
        {
            printf("Введёные числа должны быть целыми!\n");
            exit(4);
        }

        int a = str_int(str_a);
        int b = str_int(str_b);

        flag_m(a, b);

    }
    else if (strcmp("-t", flag) == 0)
    {
        char * str_eps, * str_a, * str_b, * str_c;
        if (argc != 6)
        {
            printf("Должно быть введено 4 вещественных значения!\n");
            exit(1);
        }

        str_eps = argv[2]; str_a = argv[3]; str_b = argv[4]; str_c = argv[5];

        if (!check_double(str_eps) 
        ||  !check_double(str_a) 
        || !check_double(str_b) 
        || !check_double(str_c))
        {
            printf("Введёные числа должны быть вещественными!\n");
            exit(2);
        }

        double eps = str_double(str_eps);
        double a = str_double(str_a);
        double b = str_double(str_b);
        double c = str_double(str_c);

        flag_t(eps, a, b, c);      
    } 

    
    
    return 0;
}