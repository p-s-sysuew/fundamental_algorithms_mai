#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/functions.h"


int main(int argc, char * argv[])
{
    if (argc  != 3)
    {
        printf("Должно быть введено целое число и один из флагов\n");
        printf("Пример: main.c 12 -p\n\n");
        menu();
        exit(1);
    }

    char * str_x = argv[1];
    if (!check(str_x)) 
    {
        printf("Должно быть введено целое число!\n");
        exit(2);
    }
    int x = str_int(str_x);
    

    char * flag = argv[2];
    if (strcmp("-h", flag) == 0)
    {
        flag_h(x);
    }

    
    return 0;
    
}