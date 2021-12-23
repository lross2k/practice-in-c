#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    /* Instantiate variables */
    int size = 5, min = 0, max = 0, number = 0, pick = 0, iterations = 0, found = 0;
    int *array = NULL;
    time_t t = 0;
    srand((unsigned) time(&t));

    /* Check if size should be changed */
    if (argc > 1)
        size = strtol(argv[1], NULL, 10);

    /* Allocate memory for the array */
    array = (int *) malloc(sizeof(int) * size);

    /* Populate the array */
    int i;
    for (i = 0; i < size; i++)
        array[i] = i + 1;

    /* Define a random value to be searched */
    number = 1 + rand() % size;
    printf("The computer must find %i\n", number);

    /* Binary search implementation */
    min = 0;
    max = size - 1;
    
    do
    {
        iterations++;
        pick = min + (max - min)/2;
        printf("Current pick is %i, giving %i\n", pick, array[pick]);
        if (array[pick] == number)
        {
            found = 1;
        }
        else if (array[pick] > number)
        {
            printf("New max is %i\n", pick);
            max = pick - 1; 
        }
        else
        {
            printf("New min is %i\n", pick);
            min = pick + 1;
        }
        printf("Min %i Max %i Number %i\n", min, max, number);
    } while (!found);
    printf("Found the number %i\nIterarions: %i\n", array[pick], iterations);

    /* Free memory */
    free(array);
    array = NULL;

    return(0);
}

