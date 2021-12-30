#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "AllDS.h"

#define HASH_ERROR 0xFFFFFFF
#define STRCAST(VAL) (char*)VAL
#define INTCAST(VAL) *((int*)VAL)

uint32_t hash(void *key, size_t size, uint32_t array_size)
{
    uint32_t hash_value = 0;
    char *str;
    switch(size) {
    case INT:
        hash_value = (INT+(INTCAST(key) << 1)*INTCAST(key))%array_size;
        break;
    case STR:
        str = STRCAST(key);
        hash_value = ((STR & str[0])+(str[0]+str[strlen(str)-1])*(strlen(str) << 1))%array_size;
        break;
    default:
        return HASH_ERROR%array_size;
    }
    return hash_value;
}

uint32_t ht_construct(htable_t *table, uint32_t array_size)
{
    uint32_t i;
    /* Allocate struct array to heap memory */
    htnode_t **the_array = (htnode_t **) malloc(sizeof(htnode_t)*array_size);
    /* Initialize the array to NULL */
    for (i = 0; i < array_size; i++)
        the_array[i] = (htnode_t *) NULL;
    table->array = the_array;
    table->length = array_size;
    return(0);
}

int nodecmp(htnode_t *table_node, void *key, size_t key_size)
{
    /* Return -1 if keys aren't of the same type/size */
    if (key_size != table_node->key_size)
        return(-1);

    switch(key_size) {
    case INT:
        return((INTCAST(key) == INTCAST(table_node->key)) ? 1 : 0);
    case STR:
        return(!strncmp(STRCAST(key),STRCAST(table_node->key),
               strlen(STRCAST(table_node->key))));
    default:
        return(-1);
    }
}

uint32_t ht_add(htable_t *table, htnode_t *node)
{
    uint32_t hashed = hash(node->key, node->key_size, table->length);    
    htnode_t *next = NULL;
    if (table->array[hashed] == NULL)
    {
        table->array[hashed] = node;
    }
    else /* In case of collision */
    {
        next = table->array[hashed]->next;
        if (next == NULL)
        {
            table->array[hashed]->next = node;
            return(0);
        }
        while (next != NULL)
        {
            next = next->next;
        }
        next = node;
    }
    return(0);
}

uint32_t htnode_construct(htnode_t *node, void *key, void *value, size_t ksize)
{
    node->key = key;
    node->value = value;
    node->key_size = ksize;
    node->next = NULL;
    return(0);
}

htnode_t * ht_get(htable_t *table, void *key, size_t key_s)
{
    uint32_t hashed = hash(key, key_s, table->length);    
    htnode_t *next = NULL;
    if (table->array[hashed] == NULL)
        return NULL;
    
    next = table->array[hashed];
    do {
        if (nodecmp(next, key, key_s) == 1)
            return(next);
        next = next->next;
    } while (next != NULL);
    return(NULL);   
}

htnode_t * ht_remove(htable_t *table, void *key, size_t key_s)
{
    uint32_t hashed = hash(key, key_s, table->length);    
    htnode_t *next= NULL;
    if (table->array[hashed] == NULL)
        return(NULL);
    
    next = table->array[hashed];
    do {
        if (nodecmp(next, key, key_s) == 1)
        {
            table->array[hashed] = (next->next != NULL) ? next->next : NULL;
            return(next);
        }
        next = next->next;
    } while (next != NULL);
    return(NULL);   
}

void htnode_print(htnode_t *node)
{
    switch(node->key_size) {
    case INT:
        printf("<%i>", INTCAST(node->key));
        break;
    case STR:
        printf("<%s>",STRCAST(node->key));
        break;
    default:
        printf("<unknown-type>");
    }   
}

uint32_t ht_print(htable_t *table)
{
    uint32_t i;
    htnode_t *next = NULL;

    printf("\nHash Table Start");
    for (i = 0; i < table->length; i++)
    {
        if (table->array[i] != NULL)
        {
            printf("\n - ");
            htnode_print(table->array[i]);
            next = table->array[i]->next;
            while (next != NULL)
            {
                printf(", ");
                htnode_print(next);
                next = next->next;
            }
        }
    }
    printf("\nHash Table End\n\n");
    return(0);   
}

uint32_t ht_free(htable_t *table)
{
    if (table != NULL && table->array != NULL)
    {
        free(table->array);
        table->array = NULL;
        return(0);
    }
    return(1);
}
