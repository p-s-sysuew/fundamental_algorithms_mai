#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/functions.h"


int main(int argc, char * argv[])
{
    if (argc  != 3)
    {
        printf("Должно быть введено целое число и один из флагов\n");
        printf("Пример: main.c -p 12\n\n");
        menu();
        exit(1);
    }


    char * str_x = argv[2];
    if (!check(str_x)) 
    {
        printf("Должно быть введено допустимое целое число!\n");
        exit(2);
    }
    int x = str_int(str_x);
    

    char * flag = argv[1];


    if (strcmp("-h", flag) == 0) flag_h(x);
    else if (strcmp("-p", flag) == 0) flag_p(x);
    else if (strcmp("-s", flag) == 0) flag_s(x);
    else if (strcmp("-e", flag) == 0) flag_e(x);
    else if (strcmp("-a", flag) == 0) flag_a(x);
    else if (strcmp("-f", flag) == 0) flag_f(x);
    else
    {
        printf("Недопустимый фид флага\n");
        printf("Используйте один из следующих флагов:\n");
        menu();

    }
    printf("\n");
    return 0;
    
}