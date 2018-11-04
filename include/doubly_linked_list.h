#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

/**
 * @struct dll_node
 * @brief the node struct for a doubly linked list
 */
struct dll_node{
    int key;            /**< @brief the key of the node */
    dll_node* next;     /**< @brief the pointer to the next node in a doubly linked list */
    dll_node* prev;     /**< @brief the pointer to the previous node in a doubly linked list */
};

/**
 * @struct doubly_linked_list
 * @brief the struct of a circular doubly linked list
 */
struct doubly_linked_list{
    dll_node nil;       /**< @brief the sentinel of a doubly linked list, it makes the list circular. */
};

/**
 * @fn void construct_doubly_linked_list(doubly_linked_list* list)
 * @brief construct a circular doubly linked list
 * @param list the doubly linked list
 */
void construct_doubly_linked_list(doubly_linked_list* list);

/**
 * @fn void destruct_doubly_linked_list(doubly_linked_list* list)
 * @brief destruct a circular doubly linked list, delete all nodes in the list
 * @param list the doubly linked list
 */
void destruct_doubly_linked_list(doubly_linked_list* list);

/**
 * @fn dll_node* search_doubly_linked_list(doubly_linked_list* list, int key)
 * @brief search a doubly linked list\n
 *        if found, return the address of the node, otherwise return the sentinel
 * @param list the doubly linked list
 * @param key a searching key
 */
dll_node* search_doubly_linked_list(doubly_linked_list* list, int key);

/**
 * @fn void insert_doubly_linked_list(doubly_linked_list* list, int key)
 * @brief insert a node into the doubly linked list
 * @param list the doubly linked list
 * @param key a inserting key
 */
void insert_doubly_linked_list(doubly_linked_list* list, int key);

/**
 * @fn void delete_doubly_linked_list(doubly_linked_list* list, dll_node* node)
 * @brief delete a node from the doubly linked list
 * @param list the doubly linked list
 * @param node the node to be deleted
 */
void delete_doubly_linked_list(doubly_linked_list* list, dll_node* node);

#endif // DOUBLY_LINKED_LIST_H