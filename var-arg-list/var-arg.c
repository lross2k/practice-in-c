#include <stdio.h>
#include <stdarg.h>

void counter(int amount, ...);

int main(void)
{
    counter(5,2,4,6,7,3);
    return(0);
}

void counter(int amount, ...)
{
    int total = 0, i;
    va_list parameters;
    va_start(parameters,amount);

    for (i = 0; i < amount; i++)
        total += va_arg(parameters, int);
    va_end(parameters);
    printf("%d\n", total);
}

