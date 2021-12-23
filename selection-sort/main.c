#include <stdio.h>

/* Swap items for an int array pointer between given positions */
void swap_items(int *array, int start, int to_swap)
{
    int temp = array[start];
    array[start] = array[to_swap];
    array[to_swap] = temp;
}

/* Move the next lowest value to the last position */
void next_lowest_value(int *array, size_t size, int start_index)
{
    /* Needed variables */
    int it, lowest_index = start_index;

    /* Find next lowest value */
    for (it = start_index + 1; it < size; it++)
        lowest_index = (array[it] < array[lowest_index]) ? it : lowest_index;

    /* Swap to start index */
    swap_items(array, start_index, lowest_index);
}

void select_sort(int *array, size_t size)
{
    int it;
    for (it = 0; it < size; it++)
        next_lowest_value(array, size, it);

    for (it = 0; it < size; it++)
        printf("At index %i got %i\n", it, array[it]);
}

int main(void)
{
    /* Initiate the array */
    int array[] = {18, 6, 66, 44, 9, 22, 14};

    /* Call to sort the array */
    select_sort(array, sizeof(array)/sizeof(*array));

    return(0);
}
