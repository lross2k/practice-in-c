#include <stdlib.h>
#include <stdio.h>

#include "AllDS.h"

struct bt_node * new_bt_node(int val)
{
    struct bt_node *new_node = (struct bt_node *) malloc(sizeof(struct bt_node));
    (*new_node).value = val;
    (*new_node).left = NULL;
    (*new_node).right = NULL;
    return(new_node);
}

void list_to_bt(struct bt_node *root, inode_t *node)
{
    struct bt_node *top;
    struct btn_queue queue;
    if (!root || !node)
        return;
    new_btn_queue(&queue);
    root->value = node->data;
    root->left = root->right = NULL;
    btn_enqueue(&queue, root);
    node = node->next; 
    do {
        top = btn_dequeue(&queue);
        top->left = new_bt_node(node->data);
        btn_enqueue(&queue, top->left);
        node = node->next; 
        if (node)
        {
            top->right = new_bt_node(node->data);
            btn_enqueue(&queue, top->right);
            node = node->next;
        }
    } while(node);
    btn_queue_free(&queue);
}

void inorder_traversal(struct bt_node *root)
{
    if (root)
    {
        inorder_traversal(root->left);
        printf("%i ",root->value);
        inorder_traversal(root->right);
    }
}
