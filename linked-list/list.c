#include <stdio.h>
#include <stdlib.h>

struct list_entry {
    struct list_entry *next;
    int data;
};

struct linked_list {
    struct list_entry *head;
    struct list_entry *tail;
    int length;
};

struct linked_list* linked_list()
{
    struct linked_list* new_list = (struct linked_list *) malloc (sizeof(struct linked_list));
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

int list_add(struct linked_list* list, int item)
{
    struct list_entry *tmp = (struct list_entry *) malloc(sizeof(struct list_entry));
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

/*
int list_get_index(struct linked_list* list, int index)
{
    int it = 0;
    struct list_entry *entry = list->head;
    while(it < list->length)
    {
        if (it == index)
            return entry->data;
        entry = entry->next;
        it++;
    }
    return(0);
}
*/

void free_list(struct linked_list* list)
{
    struct list_entry *current = list->head, *next;
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

void list_remove_index(struct linked_list *list, int index)
{
    int it = 0;
    struct list_entry *current = list->head, *previous = NULL, *next;
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

void list_set_index(struct linked_list *list, int index, int data)
{
    int it;
    struct list_entry *current = list->head;
    for (it = 0; it < list->length; it++)
    {
        if (it == index)
            current->data = data;
        current = current->next;
    }
}

int list_get_index(struct linked_list *list, int index)
{
    int it;
    struct list_entry *current = list->head;
    for (it = 0; it < list->length; it++)
    {
        if (it == index)
            return(current->data);
        current = current->next;
    }
    return(0);
}

void print_list(struct linked_list *list)
{
    int it;
    struct list_entry *current = list->head;
    printf("(");
    for (it = 0; it < list->length; it++)
    {
        printf("%i, ", current->data);
        current = current->next;
    }
    printf("\b\b)\n");
}

int main(void)
{
    struct linked_list *list = linked_list();

    list_add(list, 5);
    list_add(list, 4);
    list_add(list, 3);
    list_add(list, 2);
    list_add(list, 1);

    print_list(list);

    printf("The index 3 has %i\n", list_get_index(list, 3));

    list_set_index(list, 3, 9);

    printf("Now the index 3 has %i\n", list_get_index(list, 3));

    list_remove_index(list, 2);
    print_list(list);

    free_list(list);

    return(0);
}
