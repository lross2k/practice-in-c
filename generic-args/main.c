#include <stdio.h>

/* Returns the greater one */
void* compare_float(void* first, void* second)
{
    return (*(float*)first > *(float*)second) ? first : second;
}

void* compare_int(void* first, void* second)
{
    return (*(int*)first > *(int*)second) ? first : second;
}

void *gen_comp(void* (*comp_func)(void*,void*), void *first, void *second)
{
    return comp_func(first,second);
}

int main(void)
{
    void *(*comp1)(void*,void*);
    void *(*comp2)(void*,void*);
    float num1, num2, max1;
    int num3, num4;
    int *max2;
    comp1 = &compare_float;
    num1 = 5.2f;
    num2 = 4.2f;
    max1 = *(float*)gen_comp(comp1,&num1,&num2);
    printf("Between %f and %f, got %f as max\n", num1, num2, max1);
    
    comp2 = &compare_int;
    num3 = 2;
    num4 = 8;
    max2 = gen_comp(comp2,&num3,&num4);
    printf("Between %i and %i, got %i as max\n", num3, num4, *max2);
   
    return(0);
}

