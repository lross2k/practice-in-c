#include <stdio.h>
#include <stdlib.h>

/* No memoization */
int factorial(int n)
{
    return((n == 0) ? 1 : n*factorial(n - 1));
}

int main(int argc, char **argv)
{
    int n = (argc == 2) ? strtol(argv[1], NULL, 10) : 10;

    printf("Factorial of %i is %i\n", n, factorial(n));

    return(0);
}
