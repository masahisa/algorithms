#ifndef HASH_PROBING
#define HASH_PROBING

#include "hash_function.h"

/**
 * @class hash_probing
 * @brief the base class of hash probing
 */
class hash_probing {
protected:
    int m_;     /**< @brief the size of the hash table */
public:
    /**
     * @fn hash_probing(int m)
     * @brief constructer
     * @param m the size of the hash table
     */
    hash_probing(int m);
    /**
     * @fn virtual ~hash_probing()
     * @brief destructor
     */
    virtual ~hash_probing();
    /**
     * @fn virtual int hash(int k, int i) = 0
     * @brief pure virtual hash function that will be implemented in derived classes
     * @param k key
     * @param i the probe number starting from 0 to m - 1
     * @return the hash value of the key
     */
    virtual int hash(int k, int i) = 0;
};

/**
 * @class linear_probing
 * @brief the hash function using linear probing
 */
class linear_probing : public hash_probing {
private:
    hash_function* f_;      /**< @brief the pointer to a hash function */
public:
    /**
     * @fn linear_probing(int m, hash_function* f)
     * @brief constructer
     * @param m the size of the hash table
     * @param f the pointer to a hash function
     */
    linear_probing(int m, hash_function* f);
    /**
     * @fn ~linear_probing()
     * @brief destructor
     */
    ~linear_probing();
    /**
     * @fn int hash(int k, int i) override
     * @brief hash by linear probing
     * @param k key
     * @param i the probe number starting from 0 to m - 1
     * @return the hash value of the key
     */
    int hash(int k, int i) override;
};

/**
 * @class quadratic_probing
 * @brief the hash function using quadratic probing
 */
class quadratic_probing : public hash_probing {
private:
    hash_function* f_;      /**< @brief the pointer to a hash function */
    int c1_;                /**< @brief any integer */
    int c2_;                /**< @brief any integer */
public:
    /**
     * @fn quadratic_probing(int m, hash_function* f, int c1, int c2)
     * @brief constructer
     * @param m the size of the hash table
     * @param f the pointer to a hash function
     * @param c1 any integer
     * @param c2 any integer
     */
    quadratic_probing(int m, hash_function* f, int c1, int c2);
    /**
     * @fn ~quadratic_probing()
     * @brief destructor
     */
    ~quadratic_probing();
    /**
     * @fn int hash(int k, int i) override
     * @brief hash by quadratic probing
     * @param k key
     * @param i the probe number starting from 0 to m - 1
     * @return the hash value of the key
     */
    int hash(int k, int i) override;
};

/**
 * @class double_hashing
 * @brief the hash function using double hashing
 */
class double_hashing : public hash_probing {
private:
    hash_function* f1_;     /**< @brief the pointer to a hash function */
    hash_function* f2_;     /**< @brief the pointer to a hash function */
public:
    /**
     * @fn double_hashing(int m, hash_function* f1, hash_function* f2)
     * @brief constructer
     * @param m the size of the hash table
     * @param f1 the pointer to a hash function
     * @param f2 the pointer to a hash function
     */
    double_hashing(int m, hash_function* f1, hash_function* f2);
    /**
     * @fn ~double_hashing()
     * @brief destructor
     */
    ~double_hashing();
    /**
     * @fn int hash(int k, int i) override
     * @brief hash by double hashing
     * @param k key
     * @param i the probe number starting from 0 to m - 1
     * @return the hash value of the key
     */
    int hash(int k, int i) override;
};

#endif // HASH_PROBING