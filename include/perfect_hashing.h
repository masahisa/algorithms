#ifndef PERFECT_HASHING_H
#define PERFECT_HASHING_H

#include <vector>
#include <cstdint>
#include "hash_function.h"

/**
 * @var const int HASH_NIL
 * @brief the null status code
 */
const int HASH_NIL = INT32_MIN;

/**
 * @class secondary_hash_table
 * @brief the class of secondary hash table for perfect hashing, the optimal m, p, a and b need to be configured
 */
class secondary_hash_table {
private:
    int m_;                         /**< @brief the size of the hash table */
    int a_;                         /**< @brief any integer, a = 1, 2, ..., p - 1 */
    int b_;                         /**< @brief any integer, b = 0, 1, ..., p - 1 */
    universal_hash_function f_;     /**< @brief the pointer to a universal hashing function */
    std::vector<int> t_;            /**< @brief the secondary hash table */
public:
    /**
     * @fn secondary_hash_table
     * @brief default constructer
     */
    secondary_hash_table();
    /**
     * @fn secondary_hash_table(int m, int p, int a, int b)
     * @brief constructer
     * @param m the size of the hash table
     * @param p a prime number, p > m
     * @param a any integer, a = 1, 2, ..., p - 1
     * @param b any integer, b = 0, 2, ..., p - 1
     */
    secondary_hash_table(int m, int p, int a, int b);
    /**
     * @fn ~secondary_hash_table()
     * @brief destructor
     */
    ~secondary_hash_table();
    /**
     * @fn void insert_key(int k)
     * @brief insert a node to the secondary hash table
     * @param k a inserting key
     */
    void insert_key(int k);
    /**
     * @fn int* search_key(int k)
     * @brief search a secondary hash table\n
     *        if found, return the address of the node, otherwise return nullptr
     * @param k a searching key
     * @return the address of the found node or nullptr
     */
    int* search_key(int k);
    /**
     * @fn void delete_key(int k)
     * @brief delete a node from the secondary hash table
     * @param k the key to be deleted
     */
    void delete_key(int k);
};

/**
 * @class perfect_hashing
 * @brief the class of perfect hash table, the optimal m, p, a and b need to be configured
 */
class perfect_hashing {
private:
    int m_;                                     /**< @brief the size of the hash table */
    int p_;                                     /**< @brief a prime number, p > m */
    int a_;                                     /**< @brief any integer, a = 1, 2, ..., p - 1 */
    int b_;                                     /**< @brief any integer, b = 0, 2, ..., p - 1 */
    universal_hash_function f_;                 /**< @brief the pointer to a universal hashing function */
    std::vector<secondary_hash_table> st_;      /**< @brief the vector of secondary hash tables */
public:
    /**
     * @fn perfect_hashing(int m, int p, int a, int b)
     * @brief constructer
     * @param m the size of the primary hash table
     * @param p a prime number, p > m
     * @param a any integer, a = 1, 2, ..., p - 1
     * @param b any integer, b = 0, 2, ..., p - 1
     */
    perfect_hashing(int m, int p, int a, int b);
    /**
     * @fn ~perfect_hashing()
     * @brief destructor
     */
    ~perfect_hashing();
    /**
     * @fn void set_secondary_hash_table(int i, int m, int a, int b)
     * @brief set the parameters of the i-th secondary hash table
     * @param m the size of the i-th secondary hash table
     * @param i the index of the secondary hash table
     * @param a any integer, a = 1, 2, ..., p - 1, for the i-th secondary hash table
     * @param b any integer, b = 0, 2, ..., p - 1, for the i-th secondary hash table
     */
    void set_secondary_hash_table(int i, int m, int a, int b);
    /**
     * @fn void insert_key(int k)
     * @brief insert a node to the perfect hash table
     * @param k a inserting key
     */
    void insert_key(int k);
    /**
     * @fn int* search_key(int k)
     * @brief search a perfect hash table\n
     *        if found, return the address of the node, otherwise return nullptr
     * @param k a searching key
     * @return the address of the found node or nullptr
     */
    int* search_key(int k);
    /**
     * @fn void delete_key(int k)
     * @brief delete a node from the perfect hash table
     * @param k the key to be deleted
     */
    void delete_key(int k);
};

#endif // PERFECT_HASHING_H