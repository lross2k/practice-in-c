#include <stdio.h>

int is_even(int num)
{
    return(num%2==0);
}

float int_power(int x, int n)
{
    float result = 1;

    if (n > 0 && is_even(n))
    {
        result = int_power(x, n/2);
        result *= result;
    }
    else if (n > 0)
    {
        result = x*int_power(x, n-1);
    }
    else if (n < 0)
    {
        result = 1/int_power(x, -n);
    }

    return result;
}

void calc_power(int x, int n)
{
    printf("Power of %i to the %i equals %f\n", x, n, int_power(x, n));
}

int main(void)
{
    calc_power(2, 2);
    calc_power(3, 2);
    calc_power(0, 2);
    calc_power(2, -2);
    return(0);
}
