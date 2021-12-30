#include <stdlib.h>
#include <stdio.h>

#include "AllDS.h"

unsigned int stack_push(struct stack *stck, void *value)
{
    struct stack_entry *new = (struct stack_entry *) malloc(sizeof(struct stack_entry));
    if (stck == NULL || new == NULL)
        return(1);
    new->next = (stck->first != NULL) ? stck->first : NULL;
    stck->first = new;
    stck->first->value = value;
    return(0);
}
struct stack_entry * stack_pop(struct stack *stck)
{
    struct stack_entry *o_first;
    if (stck == NULL)
        return(NULL);
    o_first = stck->first;
    stck->first = (stck->first->next == NULL) ? NULL : stck->first->next;
    return(o_first);
}
unsigned int new_stack(struct stack *stck, size_t data_size)
{
    if (stck == NULL)
        return(1);
    stck->first = NULL;
    stck->data_size = data_size;
    stck->length = 0;
    return(0);
}
unsigned int new_stack_entry(struct stack_entry *entry, void *value)
{
    if (entry == NULL)
        return(1);
    entry->value = value;
    entry->next = NULL;
    return(0);
}

unsigned int stack_print(struct stack *stck)
{
    struct stack_entry *next;
    if (stck == NULL)
        return(1);
    next = stck->first;
    printf("[");
    while(next != NULL) 
    {
        switch(stck->data_size) {
        case sizeof(int):
            printf("%i, ", *((int *) next->value));
            break;
        case sizeof(char*):
            printf("%s, ", (char *) next->value);
            break;
        default:
            printf("$unknown_type$, ");
            break;
        }
        next = next->next;
    }
    printf("\b\b]\n");
    return(0);
}

unsigned int stack_free(struct stack *stck)
{
    struct stack_entry *next, *current;
    if (stck == NULL)
        return(1);
    next = stck->first;
    while(next != NULL) 
    {
        current = next;
        next = next->next;
        free(current);
        current = NULL;
    }
    return(0);
}
