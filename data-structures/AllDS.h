#ifndef ALL_DS_H
#define ALL_DS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/************************
 *     Linked lists     *
 ************************/

struct int_node {
    struct int_node *next;
    int data;
};

/* Syntactic sugar for people that don't want to write 'struct' */
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

/************************
 *      Hash Tables     *
 ************************/

struct ht_node {
    void *key;
    void *value;
    size_t key_size;
    struct ht_node *next;
};

typedef struct ht_struct {
    struct ht_node **array;
    uint32_t length;
} htable_t;

typedef struct ht_node htnode_t; /* Sugar */

enum type_sizes {
    INT = sizeof(int),
    STR = sizeof(char *)
};

uint32_t hash(void *key, size_t size, uint32_t array_size);
uint32_t ht_construct(htable_t *table, uint32_t array_size);
uint32_t ht_add(htable_t *table, htnode_t *node);
htnode_t * ht_get(htable_t *table, void *key, size_t key_s);
htnode_t * ht_remove(htable_t *table, void *key, size_t size);
uint32_t htnode_construct(htnode_t *node, void *key, void *value, size_t ksize);
uint32_t ht_free(htable_t *table);
uint32_t ht_print(htable_t *table);

#endif /*ALL_DS_H*/
