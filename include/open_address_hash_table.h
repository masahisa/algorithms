#ifndef OPEN_ADDRESS_HASH_TABLE_H
#define OPEN_ADDRESS_HASH_TABLE_H

#include "hash_probing.h"

/**
 * @struct open_address_hash_table
 * @brief the struct of open address hash table
 */
struct open_address_hash_table {
    int* table;                 /**< @brief the pointer to the table */
    int m;                      /**< @brief the size of the hash table */
    hash_probing* function;     /**< @brief the pointer to a hash function */
};

/**
 * @fn construct_open_address_hash_table(open_address_hash_table* t, int m, hash_probing* f)
 * @brief constructs a open address hash table
 * @param t the pointer to the open address hash table
 * @param m the size of the hash table
 * @param f the pointer to a hash function
 */
void construct_open_address_hash_table(open_address_hash_table* t, int m, hash_probing* f);

/**
 * @fn void destruct_open_address_hash_table(open_address_hash_table* t)
 * @brief destructs a open address hash table
 * @param t the pointer to the open address hash table
 */
void destruct_open_address_hash_table(open_address_hash_table* t);

/**
 * @fn bool open_address_hash_table_insert(open_address_hash_table* t, int key)
 * @brief insert a node to the open address hash table
 * @param t the pointer to the open address hash table
 * @param key a inserting key
 * @return whether insert operation is successful (true) or not (false)
 */
bool open_address_hash_table_insert(open_address_hash_table* t, int key);

/**
 * @fn int open_address_hash_table_search(open_address_hash_table* t, int key)
 * @brief search a open address hash table\n
 *        if found, return the index of the node, otherwise return INT32_MIN
 * @param t the pointer to the open address hash table
 * @param key a searching key
 * @return the index of the found node or INT32_MIN
 */
int open_address_hash_table_search(open_address_hash_table* t, int key);

/**
 * @fn bool open_address_hash_table_delete(open_address_hash_table* t, int key)
 * @brief delete a node from the open address hash table
 * @param t the pointer to the open address hash table
 * @param key the key to be deleted
 * @return whether delete operation is successful (true) or not (false)
 */
bool open_address_hash_table_delete(open_address_hash_table* t, int key);

#endif // OPEN_ADDRESS_HASH_TABLE_H