#include "list.h"

int list_is_empty(linked_list *list){
    return list->next == NULL;
}

linked_list *generate_empty_list(){
    linked_list *list = (linked_list *) malloc(sizeof(linked_list));
    list->next = NULL;
    return list;
}


void head_insert(linked_list *list, int data) {
    struct list_node *new = (struct list_node *)malloc(sizeof(struct list_node));
    new->data = data;
    
    new->next = list->next;
    list->next = new;
    return ;
}

void print_list(linked_list *list) {
    linked_list* tmp = list->next;
    while(tmp != NULL){
        printf("%d->",tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
    return;
}

linked_list *reverse_list(linked_list* list){
    linked_list *current = list->next, *next;
    list->next = NULL;
    while( NULL != current){
        next = current->next;
        current->next = list->next;
        list->next = current;
        current = next;
    }
    return list;
}

int list_find(linked_list *list, int data){
    linked_list *tmp = list->next;
    while(NULL != tmp){
        if(tmp->data == data)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

int list_delete(linked_list *list, int data){
    linked_list *tmp = list->next;
    linked_list *previous = list;
    while( NULL!= tmp){
        if(tmp->data == data){
            previous->next = tmp->next;
            free(tmp);
            return 1;
        }
        else{
            previous = tmp;
            tmp = tmp->next;
        }
    }
    return 0;
}

int list_delete_index(linked_list *list , int index){
    linked_list *tmp = list;
    while(index>1 && tmp->next !=NULL){
        tmp = tmp->next;
        index--;
    }
    if(tmp->next == NULL){
        return 0;
    }
    if(index ==1){
        linked_list *deleted = tmp->next;
        tmp->next = deleted->next;
        free(deleted);
        return 1;
    }

}

/*
struct list_head {
    struct list_head *next, *prev;
}

static inline void INIT_LIST_HEAD(struct list_head *list){
    list->next = list;
    list->prev = list;
}

void list_add(struct list_head *new, struct list_head *head) {
    __list_add(new, head->prev, head->next)
}

static incline void __list_add(struct list_head *new,
    struct list_head *prev,
    struct list_head *next){
    new->next = next;
    next->prev = new;
    new->prev = prev;
    prev->next = new;
}
*/