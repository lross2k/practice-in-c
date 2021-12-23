#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    int result = 1;

    int it;
    for(it = 2; it <= n; it++)
        result *= it;

    return result;
}

int main(int argc, char **argv)
{
    int n = (argc == 2) ? strtol(argv[1], NULL, 10) : 10;

    printf("Factorial of %i is %i\n", n, factorial(n));
        
    return(0);
}