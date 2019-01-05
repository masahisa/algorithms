#ifndef HASH_FUNCTION_H
#define HASH_FUNCTION_H

/**
 * @fn int division_method(int k, int m)
 * @brief calculates the hash value of the key by division method
 * @param k key
 * @param m a prime number not too close to an exact power of 2
 * @retrun the hash value of the key
 */
int division_method(int k, int m);

/**
 * @fn int multiplication_method(int k, int m, double A)
 * @brief calculates the hash value of the key by multiplication method
 * @param k key
 * @param m typically a power of 2
 * @param A a constant value in the range 0 < A < 1, Knuth suggests A = (sqrt(5) - 1) / 2
 * @retrun the hash value of the key
 */
int multiplication_method(int k, int m, double A);

/**
 * @fn int universal_hashing(int k, int m, int p, int a, int b)
 * @brief calculates the hash value of the key by universal hashing \n
 *        param a and b are used for randomization.
 * @param k key
 * @param m the size of the hash table, not necessarily prime
 * @param p a prime number, p > m
 * @param a any integer, a = 1, 2, ..., p - 1
 * @param b any integer, b = 0, 1, ..., p - 1
 * @return the hash value of the key
 */
int universal_hashing(int k, int m, int p, int a, int b);

/**
 * @class hash_function
 * @brief the base class of hash function
 */
class hash_function {
protected:
    int m_;     /**< @brief the size of the hash table */
public:
    /**
     * @fn hash_function(int m)
     * @brief constructer
     * @param m the size of the hash table
     */
    hash_function(int m);
    /**
     * @fn virtual ~hash_function()
     * @brief destructor
     */
    virtual ~hash_function();
    /**
     * @fn virtual int hash(int k) = 0
     * @brief pure virtual hash function that will be implemented in derived classes
     * @param k key
     * @return the hash value of the key
     */
    virtual int hash(int k) = 0;
};

/**
 * @class division_hash_function
 * @brief the hash function using division method
 */
class division_hash_function : public hash_function {
public:
    /**
     * @fn division_hash_function(int m)
     * @brief constructer
     * @param m the size of the hash table
     */
    division_hash_function(int m);
    /**
     * @fn ~division_hash_function()
     * @brief destructor
     */
    ~division_hash_function();
    /**
     * @fn int hash(int k) override
     * @brief hash by division method
     * @param k key
     * @return the hash value of the key
     */
    int hash(int k) override;
};

/**
 * @class multiplication_hash_function
 * @brief the hash function using multiplication method
 */
class multiplication_hash_function : public hash_function {
private:
    double A_;      /**< @brief a constant value in the range 0 < A < 1, Knuth suggests A = (sqrt(5) - 1) / 2 */
public:
    /**
     * @fn multiplication_hash_function(int m, double A)
     * @brief constructer
     * @param m the size of the hash table
     * @param A a constant value in the range 0 < A < 1, Knuth suggests A = (sqrt(5) - 1) / 2
     */
    multiplication_hash_function(int m, double A);
    /**
     * @fn ~multiplication_hash_function()
     * @brief destructor
     */
    ~multiplication_hash_function();
    /**
     * @fn int hash(int k) override
     * @brief hash by multiplication method
     * @param k key
     * @return the hash value of the key
     */
    int hash(int k) override;
};

/**
 * @class universal_hash_function
 * @brief the hash function using universal hashing
 */
class universal_hash_function : public hash_function {
private:
    int p_;     /**< @brief a prime number, p > m */
    int a_;     /**< @brief any integer, a = 1, 2, ..., p - 1 */
    int b_;     /**< @brief any integer, b = 0, 2, ..., p - 1 */
public:
    /**
     * @fn universal_hash_function(int m, int p, int a, int b)
     * @brief constructer
     * @param m the size of the hash table
     * @param p a prime number, p > m
     * @param a any integer, a = 1, 2, ..., p - 1
     * @param b any integer, b = 0, 2, ..., p - 1
     */
    universal_hash_function(int m, int p, int a, int b);
    /**
     * @fn ~universal_hash_function()
     * @brief destructor
     */
    ~universal_hash_function();
    /**
     * @fn int hash(int k) override
     * @brief hash by universal hashing
     * @param k key
     * @return the hash value of the key
     */
    int hash(int k) override;
};

#endif // HASH_FUNCTION_H