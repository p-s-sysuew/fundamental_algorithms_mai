#include <stdio.h>
#include "include/func.h"

int func(char *);

int main()
{
    char * str;
    scanf("%s", str);
    int a = func(str);
    printf("%s = %d\n", str, a);

    return 0;
}

