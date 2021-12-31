#include <stdio.h>
#include <stdlib.h>

#include "AllDS.h"

/* Forget about generics, I have done quite a bit of those 
   already an this is no modern language to be messing 
   with fancy stuff without a need */

unsigned int new_btn_queue(struct btn_queue *queue)
{
    if (queue == NULL)
        return(1);
    queue->head = queue->tail = NULL;
    return(0);
}

unsigned int btn_enqueue(struct btn_queue *queue, struct bt_node *node)
{
    struct btnq_node *new_node = (struct btnq_node*) malloc(sizeof(struct btnq_node));
    if (queue == NULL && new_node != NULL)
        return(1);
    new_node->val = node;
    new_node->next = NULL;
    if (!queue->head)
    {
        queue->head = new_node;
        return(0);
    }
    if (queue->tail)
        queue->tail->next = new_node;
    else
        queue->head->next = new_node;
    queue->tail = new_node;
    return(0);
}

struct bt_node * btn_dequeue(struct btn_queue *queue)
{
    struct btnq_node *current = NULL;
    if (!queue || !queue->head)
        return(NULL);
    current = queue->head;
    queue->head = current->next;
    if (queue->head == queue->tail)
        queue->tail = NULL;
    return(current->val);
}

unsigned int btn_queue_is_empty(struct btn_queue *queue)
{
    if (!queue)
        return(1);
    return(queue->head == NULL);
}

unsigned int btn_queue_print(struct btn_queue *queue)
{
    struct btnq_node *next;
    if(!queue)
        return(1);
    next = queue->head;
    printf("(");
    while(next != NULL)
    {
        printf("%i, ", next->val->value);
        next = next->next;
    }
    printf("\b\b)\n");
    return(0);
}

struct btn_queue * btn_queue_free(struct btn_queue *queue)
{
    struct btnq_node *next, *current;
    if(!queue)
        return(NULL);
    next = queue->head;
    while(next != NULL)
    {
        current = next;
        next = next->next;
        free(current);
    }
    return(queue);
}
