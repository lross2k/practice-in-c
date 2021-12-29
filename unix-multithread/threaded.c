/* Example from https://www.geeksforgeeks.org/multithreading-c-2/ 
   with some modifications as the code from the example had errors 
   only triggered with -Wall and -pedantic-errors */

#define _OPEN_THREADS
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*            DEFINITION OF pthread_create(...) BY POSIX
int pthread_create(pthread_t *thread, pthread_attr_t *attr,
                   void *(*start_routine) (void *arg), void *arg); */
struct values { char *string; unsigned int key; };
struct values * create_data(int key, char *string);
void * thread(void *vargp);

/* Global variable to access from threads */
struct values *data;

int main()
{
    int i;
    pthread_t tid;
    static int thread_ids[] = {0,1,2,3,4,5,6,7,8,9,10};
    data = create_data(0, "Hello World!");
  
    for (i = 0; i < 10; i++)
        pthread_create(&tid, NULL, thread, &thread_ids[i]);

    /* Free the memory */
    free(data);
    data = NULL;
    return 0;
}

struct values * create_data(int key, char *string)
{
    struct values * tmp = (struct values *) malloc(sizeof(struct values));
    tmp->string = (char *) malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(tmp->string, string);
    tmp->key = key;
    return(tmp);
}

/* The function to be executed by all threads */
void * thread(void *vargp)
{
    /* Store the value argument passed to this thread */
    unsigned int *myid = (unsigned int *)vargp;
    /* Program already finished */
    if (!data)
        pthread_exit(NULL);

    if (data->key == *myid)
    {
        printf("The thread %u modified the string %s\n", *myid, data->string);
        data->string[*myid] = 'a';
        data->key += 1;
    }
    else
    {
        printf("The thread %u read the string %s\n", *myid, data->string);
    }
  
    pthread_exit(NULL);
}
