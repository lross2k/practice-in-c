#include <stdio.h>

double my_add(double x, double y);
double my_sub(double x, double y);
double my_div(double x, double y);
void apply_funcs(int amount, double (**funcs)(double, double), double x, double y);

int main(void)
{
    double (*the_funcs[3])(double, double);

    the_funcs[0] = &my_add;
    the_funcs[1] = &my_sub;
    the_funcs[2] = &my_div;

    apply_funcs(3, the_funcs, 5, 2);

    return(0);
}

double my_add(double x, double y)
{
    return (x+y);
}

double my_sub(double x, double y)
{
    return (x-y);
}
    
double my_div(double x, double y)
{
    return (x/y);
}
    
void apply_funcs(int amount, double (**funcs)(double, double), double x, double y)
{
    printf("%f y %f \n",x,y);
    int i;
    for (i = 0; i < amount; i++)
    {
        printf("%f\n",(*funcs)(x,y));
        funcs++;
    }
}

