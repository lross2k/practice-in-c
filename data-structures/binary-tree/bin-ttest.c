#include <stdio.h>

#include "AllDS.h"

/** LINKED LIST ALREADY IMPLEMENTED IN libAllDS
 * ilist_t *list = ilist();
 * ilist_add(list, 5);
 * ilist_print(list);
 * ilist_get(list, 3)
 * ilist_set(list, 3, 9);
 * ilist_remove(list, 2);
 * ilist_free(list);
 */

int main(void)
{
    struct bt_node root;
    ilist_t *list = ilist();
    ilist_add(list, 10);
    ilist_add(list, 12);
    ilist_add(list, 15);
    ilist_add(list, 25);
    ilist_add(list, 30);
    ilist_add(list, 36);
 
    printf("List: "); ilist_print(list);
    list_to_bt(&root, list->head);
 
    printf("Inorder Traversal is: ");
    inorder_traversal(&root); puts("");
    ilist_free(list);
    return(0);
}
