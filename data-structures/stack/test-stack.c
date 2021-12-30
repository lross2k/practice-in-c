#include <stdio.h>
#include "AllDS.h"

int main(void)
{
    stack_t stck;
    int val1 = 6, val2 = 69, val3 = 50, val4 = 2;
    new_stack(&stck, sizeof(int));
    stack_push(&stck, (void *) &val1);
    stack_push(&stck, (void *) &val2);
    stack_print(&stck);
    printf("popped %i\n", *((int*)stack_pop(&stck)->value));
    stack_print(&stck);
    stack_push(&stck, (void *) &val2);
    stack_push(&stck, (void *) &val3);
    stack_push(&stck, (void *) &val4);
    stack_print(&stck);
    printf("popped %i\n", *((int*)stack_pop(&stck)->value));
    stack_print(&stck);
    stack_free(&stck);
    return(0);
}
