#include <stdio.h>
#include "AllDS.h"

int main(void)
{
    ilist_t *list = ilist();

    ilist_add(list, 5);
    ilist_add(list, 4);
    ilist_add(list, 3);
    ilist_add(list, 2);
    ilist_add(list, 1);

    ilist_print(list);

    printf("The index 3 has %i\n", ilist_get(list, 3));

    ilist_set(list, 3, 9);

    printf("Now the index 3 has %i\n", ilist_get(list, 3));

    ilist_remove(list, 2);
    ilist_print(list);

    ilist_free(list);

    return(0);
}
