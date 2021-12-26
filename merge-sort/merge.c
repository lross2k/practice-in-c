#include <stdio.h>
#include <stdlib.h>

/***************************
 * Function prototypes
 **************************/

/* Linear merge of two halves of an array */
void merge(int *array, int p, int q, int r);
/* Sorts a given int array by recursively splitting the 
 * array and finally merging the sorted subarrays */
void merge_sort(int *array, int p, int r);
/* Quick function to print arrays without explicitly 
 * declaring the type of the values (kinda generic) */
void print_array(void *array, int length, size_t type);

int main(void)
{
    /* Some array to test */
    int array[] = {-1, 6, -2, 0, 1312, 7, 7, -434, 2};

    /* Print the original array */
    print_array(array, sizeof(array)/sizeof(int), sizeof(*array));

    /* Merge sort the array and print it afterwards */
    merge_sort(array, 0, sizeof(array)/sizeof(int));
    print_array(array, sizeof(array)/sizeof(int), sizeof(*array));

    return(0);
}

/***************************
 * Function declarations 
 **************************/

void merge(int *array, int p, int q, int r)
{
    /* Declare, instantiate and allocate variables needed */
    int k = p, i, j, first_len = q-p+1, second_len = r-q;
    int *first_half = (int *) malloc(sizeof(int) * first_len);
    int *second_half = (int *) malloc(sizeof(int) * second_len);

    /* Copy the original array into each half */
    for (i = 0; k <= q; i++, k++)
        first_half[i] = array[k];

    for (j = 0; k <= r; j++, k++)
        second_half[j] = array[k];

    k = p;
    i = j = 0;
    
    /* Copies the first lowest value between the two given halves 
    until one is emptied */
    while (i < first_len && j < second_len)
    {
        if (first_half[i] < second_half[j])
        {
            array[k] = first_half[i];
            i++;
        }
        else
        {
            array[k] = second_half[j];
            j++;
        }
        k++;
    }
    
    /* Copies the remaining values from the array that is left */
    while (i < first_len)
    {
        array[k] = first_half[i];
        i++, k++;
    }
    
    while (j < second_len)
    {
        array[k] = second_half[j];
        j++, k++;
    }

    /* Frees the memory used for the temporary half arrays */
    free(first_half);
    free(second_half);
    second_half = first_half  = NULL;
}

void print_array(void *array, int length, size_t type)
{
    int it;
    switch (type) {
    case sizeof(int):
        for (it = 0; it < length; it++)
            printf("%i ", ((int *)array)[it]);
        break;
    case sizeof(char):
        for (it = 0; it < length; it++)
            printf("%c", ((char *)array)[it]);
        break;
    }
    printf("\n");
}

void merge_sort(int *array, int p, int r)
{
    int q;
    if (r-p >= 1)
    {
        q = p+(r-p)/2;
        merge_sort(array, p, q);
        merge_sort(array, q+1, r);
        merge(array, p, q, r);
    }
}
