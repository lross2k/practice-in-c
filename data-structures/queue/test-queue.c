#include <stdio.h>
#include "AllDS.h"

int main(void)
{
    struct queue_by_list *queue = new_queue();
    printf("Should be 1 => %i\n", queue_is_empty(queue));
    enqueue(queue, 9);
    printf("Should be 0 => %i\n", queue_is_empty(queue));
    enqueue(queue, 4);
    enqueue(queue, 2);
    printf("Should be 9 => %i\n", dequeue(queue));
    return(0);
}
