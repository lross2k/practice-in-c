#include <stdio.h>
#include "AllDS.h"

int main(void)
{
    htable_t table;
    htnode_t bob, sandy, patrick, mrcrabs, aa, bb, *bob_ptr;
    int a = 2, b = 6;

    htnode_construct(&bob, (void *)"Bob", NULL, STR);
    htnode_construct(&sandy, (void *)"Sandy", NULL, STR);
    htnode_construct(&patrick, (void *)"Patrick", NULL, STR);
    htnode_construct(&mrcrabs, (void *)"MrCrabs", NULL, STR);
    htnode_construct(&aa, (void *)&a, NULL, INT);
    htnode_construct(&bb, (void *)&b, NULL, INT);

    ht_construct(&table, 10);

    ht_add(&table, &bob);
    ht_add(&table, &sandy);
    ht_add(&table, &aa);
    ht_add(&table, &bb);
    ht_print(&table);

    bob_ptr = ht_get(&table, (void *)"Bob", STR);
    if (bob_ptr != NULL) printf("[get] The key to 'Bob' is %s\n", (char *)bob_ptr->key);
    ht_print(&table);

    printf("Removed Bob\n");
    ht_remove(&table, (void *)"Bob", STR);
    ht_print(&table);

    ht_add(&table, &bob);
    ht_add(&table, &patrick);
    ht_add(&table, &mrcrabs);
    ht_print(&table);

    ht_free(&table);

    return(0);
}
