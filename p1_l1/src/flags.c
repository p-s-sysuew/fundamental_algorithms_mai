#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void flag_h(int x)
{
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