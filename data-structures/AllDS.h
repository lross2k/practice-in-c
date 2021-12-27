#ifndef ALL_DS_H
#define ALL_DS_H

#include <stdio.h>
#include <stdlib.h>

/************************
 *     Linked lists     *
 ************************/

struct int_node {
    struct int_node *next;
    int data;
};

/* Syntactic sugar for people that don'w want to write 'struct' */
typedef struct int_node inode_t;

typedef struct int_list {
    inode_t *head;
    inode_t *tail;
    int length;
} ilist_t;

ilist_t* ilist();
int ilist_add(ilist_t* list, int item);
void ilist_free(ilist_t* list);
void ilist_remove(ilist_t *list, int index);
void ilist_set(ilist_t *list, int index, int data);
int ilist_get(ilist_t *list, int index);
void ilist_print(ilist_t *list);

/************************
 *        Queues        *
 ************************/

struct queue_by_list {
    ilist_t *queue_list;
};

struct queue_by_list * new_queue();
int queue_is_empty(struct queue_by_list *queue);
void enqueue(struct queue_by_list *queue, int item);
int dequeue(struct queue_by_list *queue);

#endif /*ALL_DS_H*/
