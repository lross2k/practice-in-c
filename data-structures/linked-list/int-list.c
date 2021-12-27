/* This file has a simple implementation of linked lists for int
 * data types, generics can be easily implemented passing data 
 * values as void * and passing size_t or an enum as the case 
 * deciding factor, however I didn't need a whole lib for lists */

#include "AllDS.h"

ilist_t* ilist()
{
    ilist_t* new_list = (ilist_t *) malloc (sizeof(ilist_t));
    if (!new_list)
    {
        fprintf(stderr, "ERROR: Couldn't allocate linked list\n");
        return NULL;
    }
    (*new_list).head = NULL;
    (*new_list).tail = NULL;
    (*new_list).length = 0;
    return new_list;
}

int ilist_add(ilist_t* list, int item)
{
    inode_t *tmp = (inode_t *) malloc(sizeof(inode_t));
    if (!tmp)
    {
        fprintf(stderr, "ERROR: Couldn't allocate space for new item\n");
        return(1);
    }
    if (list->tail != NULL)
    {
        list->tail->next = tmp;
        list->tail = tmp;
        tmp->data = item;
        tmp->next = NULL;
    }
    else if (list->head == NULL)
    {
        list->head = tmp;
        list->head->data = item;
        list->head->next = NULL;
    }
    else
    {
        list->tail = tmp;
        list->tail->data = item;
        list->head->next = list->tail;
        list->tail->next = NULL;
    }
    list->length++;
    return(0);
}

void ilist_free(ilist_t* list)
{
    inode_t *current = list->head, *next;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
    list = NULL;
    current = next = NULL;
}

void ilist_remove(ilist_t *list, int index)
{
    int it = 0;
    inode_t *current = list->head, *previous = NULL, *next;
    next = current->next;
    while(it < list->length)
    {
        if (it == index)
        {
            if (index > 0)
                previous->next = next;
            else
                list->head = next;
            if (current == list->tail)
                list->tail = NULL;
            free(current);
            list->length--;
            return;
        }
        previous = current;
        current = current->next;
        next = current->next;
        it++;
    }
}

void ilist_set(ilist_t *list, int index, int data)
{
    int it;
    inode_t *current = list->head;
    for (it = 0; it < list->length; it++)
    {
        if (it == index)
            current->data = data;
        current = current->next;
    }
}

int ilist_get(ilist_t *list, int index)
{
    int it;
    inode_t *current = list->head;
    for (it = 0; it < list->length; it++)
    {
        if (it == index)
            return(current->data);
        current = current->next;
    }
    return(0);
}

void ilist_print(ilist_t *list)
{
    int it;
    inode_t *current = list->head;
    printf("(");
    for (it = 0; it < list->length; it++)
    {
        printf("%i, ", current->data);
        current = current->next;
    }
    printf("\b\b)\n");
}
