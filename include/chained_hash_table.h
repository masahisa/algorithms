#ifndef CHAINED_HASH_TABLE_H
#define CHAINED_HASH_TABLE_H

#include "doubly_linked_list.h"
#include "hash_function.h"

/**
 * @struct chained_hash_table
 * @brief the struct of chained hash table
 */
struct chained_hash_table {
    doubly_linked_list* table;      /**< @brief the pointer to the table */
    int m;                          /**< @brief the size of the hash table */
    hash_function* function;        /**< @brief the pointer to a hash function */
};

/**
 * @fn void construct_chained_hash(chained_hash_table* t, int m, hash_function* f)
 * @brief constructs a chained hash table
 * @param t the pointer to the chained hash table
 * @param m the size of the hash table
 * @param f the pointer to a hash function
 */
void construct_chained_hash(chained_hash_table* t, int m, hash_function* f);

/**
 * @fn void destruct_chained_hash(chained_hash_table* t)
 * @brief destructs a chained hash table
 * @param t the pointer to the chained hash table
 */
void destruct_chained_hash(chained_hash_table* t);

/**
 * @fn void chained_hash_insert(chained_hash_table* t, int key)
 * @brief insert a node to the chained hash table
 * @param t the pointer to the chained hash table
 * @param key a inserting key
 */
void chained_hash_insert(chained_hash_table* t, int key);

/**
 * @fn dll_node* chained_hash_search(chained_hash_table* t, int key)
 * @brief search a chained hash table\n
 *        if found, return the address of the node, otherwise return the sentinel
 * @param t the pointer to the chained hash table
 * @param key a searching key
 * @return the address of the found node or the sentinel
 */
dll_node* chained_hash_search(chained_hash_table* t, int key);

/**
 * @fn void chained_hash_delete(chained_hash_table* t, dll_node* x)
 * @brief delete a node from the chained hash table
 * @param t the pointer to the chained hash table
 * @param node the node to be deleted
 */
void chained_hash_delete(chained_hash_table* t, dll_node* node);

#endif // CHAINED_HASH_TABLE_H