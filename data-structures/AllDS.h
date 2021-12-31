#ifndef ALL_DS_H
#define ALL_DS_H

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

typedef struct queue_by_list {
    ilist_t *queue_list;
} iqueue_t;

struct queue_by_list * new_queue();
int queue_is_empty(struct queue_by_list *queue);
void enqueue(struct queue_by_list *queue, int item);
int dequeue(struct queue_by_list *queue);
void queue_print(struct queue_by_list *queue);
int queue_free(struct queue_by_list *queue);

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
    unsigned int length;
} htable_t;

typedef struct ht_node htnode_t; /* Sugar */

enum type_sizes {
    INT = sizeof(int),
    STR = sizeof(char *)
};

unsigned int hash(void *key, size_t size, unsigned int array_size);
unsigned int ht_construct(htable_t *table, unsigned int array_size);
unsigned int ht_add(htable_t *table, htnode_t *node);
htnode_t * ht_get(htable_t *table, void *key, size_t key_s);
htnode_t * ht_remove(htable_t *table, void *key, size_t size);
unsigned int htnode_construct(htnode_t *node, void *key, void *value, size_t ksize);
unsigned int ht_free(htable_t *table);
unsigned int ht_print(htable_t *table);

/************************
 *        Stacks        *
 ************************/

struct stack_entry {
    void *value;
    struct stack_entry *next;
};

typedef struct stack {
    unsigned int length;
    size_t data_size;
    struct stack_entry *first;
} stack_t;

unsigned int stack_push(struct stack *stck, void *value);
struct stack_entry * stack_pop(struct stack *stck);
unsigned int new_stack(struct stack *stck, size_t data_size);
unsigned int new_stack_entry(struct stack_entry *entry, void *value);
unsigned int stack_print(struct stack *stck);
unsigned int stack_free(struct stack *stck);

/************************
 *     Binary trees     *
 ************************/

struct bt_node {
    int value;
    struct bt_node *left, *right;
};

/* Quickly implement queue for bt_node */
struct btnq_node {
    struct bt_node *val;
    struct btnq_node *next;
};

struct btn_queue {
    struct btnq_node *head, *tail;
};

unsigned int new_btn_queue(struct btn_queue *queue);
unsigned int btn_enqueue(struct btn_queue *queue, struct bt_node *node);
struct bt_node * btn_dequeue(struct btn_queue *queue);
unsigned int btn_queue_is_empty(struct btn_queue *queue);
unsigned int btn_queue_print(struct btn_queue *queue);
struct btn_queue * btn_queue_free(struct btn_queue *queue);

void inorder_traversal(struct bt_node *root);
void list_to_bt(struct bt_node *root, inode_t *list);
struct bt_node * new_bt_node(int val);

#endif /*ALL_DS_H*/
