#include <stdio.h>

void insert(int *array, int right_index, int val)
{
    int it;
    for (it = right_index; (it >= 0) && (array[it] > val); it--)
        array[it + 1] = array[it];
    array[it + 1] = val;
}

void insertion_sort(int *array, size_t size)
{
    int it;
    for (it = 1; it < size; it++)
        insert(array, it-1, array[it]);
}

void print_array(int *array, size_t size)
{
    int it;
    printf("[");
    for (it = 0; it < size; it++)
        printf("%i ",array[it]);
    printf("\b]\n");
}

int main(void)
{
    int array[] = {3, 5, 7, 11, 13, 2, 9, 6};
    int array2[] = {69, -5, 5, 5, 80, -20, 0};
    size_t size = sizeof(array)/sizeof(*array);
    size_t size2 = sizeof(array2)/sizeof(*array2);

    /* Testing array 1 */
    print_array(array, size);
    insertion_sort(array, size);
    print_array(array, size);

    /* Testing array 2 */
    print_array(array2, size2);
    insertion_sort(array2, size2);
    print_array(array2, size2);

    return(0);
}
