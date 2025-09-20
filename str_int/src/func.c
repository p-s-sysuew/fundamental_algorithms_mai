#include <stdio.h>
#include "../include/func.h"


int func(char * str)
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