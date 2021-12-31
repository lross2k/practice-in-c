#include <stdio.h>
#include <stdlib.h>
#include "AllDS.h"

struct queue_by_list * new_queue()
{
    struct queue_by_list *queue = (struct queue_by_list *) malloc(sizeof(struct queue_by_list));
    if (!queue)
    {
        fprintf(stderr, "ERROR: Couldn't allocate memory for queue");
        return NULL;
    }
    (*queue).queue_list = ilist();
    if (!(*queue).queue_list)
        return NULL;
    return queue;
}

int queue_is_empty(struct queue_by_list *queue)
{
    if (!queue)
        return(1);
    return(queue->queue_list->length == 0);
}

void enqueue(struct queue_by_list *queue, int item)
{
    ilist_add(queue->queue_list, item);
}

int dequeue(struct queue_by_list *queue)
{
    int val = ilist_get(queue->queue_list, 0);
    ilist_remove(queue->queue_list, 0);
    return val;
}

/* Could be inline, but... C89 */
void queue_print(struct queue_by_list *queue)
{
    ilist_print(queue->queue_list);
}

int queue_free(struct queue_by_list *queue)
{
    if (queue == NULL)
        return(1);
    ilist_free(queue->queue_list);
    free(queue);
    queue = NULL;
    return(0);
}
