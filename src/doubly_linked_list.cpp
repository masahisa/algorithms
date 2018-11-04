#include "doubly_linked_list.h"

void construct_doubly_linked_list(doubly_linked_list* list)
{
    list->nil.key = 0;
    list->nil.next = &list->nil;
    list->nil.prev = &list->nil;
}

void destruct_doubly_linked_list(doubly_linked_list* list)
{
    while(list->nil.next != &list->nil){
        delete_doubly_linked_list(list, list->nil.next);
    }
}

dll_node* search_doubly_linked_list(doubly_linked_list* list, int key)
{
    dll_node* node = list->nil.next;
    while(node != &list->nil && node->key != key){
        node = node->next;
    }
    return node;
}

void insert_doubly_linked_list(doubly_linked_list* list, int key)
{
    dll_node* node = new dll_node;
    node->key = key;
    node->next = list->nil.next;
    list->nil.next->prev = node;
    list->nil.next = node;
    node->prev = &list->nil;
}

void delete_doubly_linked_list(doubly_linked_list* list, dll_node* node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}