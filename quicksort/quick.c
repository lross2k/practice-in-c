#include <stdio.h>

void swap(int *array, int first, int second);
int partition(int *array, int p, int r);
void quicksort(int *array, int p, int r);
void print_array(int *array, int length);

int main(void)
{
    int array[] = {-1,6,-2,0,1312,7,7,-434,2};
    int len = sizeof(array)/sizeof(*array);
    print_array(array, len);
    quicksort(array, 0, len - 1);
    print_array(array, len);
    return(0);
}

void swap(int *array, int first, int second)
{
    int tmp = array[first];
    array[first] = array[second];
    array[second] = tmp;
}

int partition(int *array, int p, int r)
{
    int q = p, j;
    for (j = p; j < r; j++)
        if (array[j] <= array[r])
        {
            swap(array, q, j);
            q++;
        }
    swap(array, r, q);
    return q;
}

void quicksort(int *array, int p, int r)
{
    int q;
    if (r-p > 0)
    {
        q = partition(array, p, r);
        quicksort(array, p, q-1);
        quicksort(array, q+1, r);
    }
}

void print_array(int *array, int length)
{
    int it;
    printf("[");
    for (it = 0; it < length; it++)
        printf("%i ", array[it]);
    printf("\b]\n");
}
