#ifndef _LIST_H_
#define _LIST_H_
#include <stdlib.h>

struct list_node{
    struct list_node *next;
    int data;
};

typedef struct list_node linked_list;

linked_list *generate_empty_list(void);

int list_is_empty(linked_list *);

void head_insert(linked_list*, int);

void print_list(linked_list*);

linked_list *reverse_list(linked_list*);

int list_find(linked_list *, int);

int list_delete(linked_list *, int);

int list_delete_index(linked_list *, int);
#endif


