#include <CppUTest/TestHarness.h>
#include "hash_probing.h"
#include <memory>

class h1 : public hash_function {
public:
    h1(int m) : hash_function(m){  }
    int hash(int k){ return k; }
};

class h2 : public hash_function {
public:
    h2(int m) : hash_function(m){  }
    int hash(int k){ return 1 + k % (m_ - 1); }
};

TEST_GROUP(hash_probing)
{
    int m = 11;
    int k = 10;
    int c1 = 1;
    int c2 = 3;
    hash_function* f1;
    hash_function* f2;
    void setup(){
        f1 = new h1(m);
        f2 = new h2(m);
    }
    void teardown(){
        delete f1;
        delete f2;
    }
};

TEST(hash_probing, linear_probing)
{
    std::unique_ptr<hash_probing> ptr = std::make_unique<linear_probing>(m, f1);
    CHECK_EQUAL(10, ptr->hash(k, 0));
}

TEST(hash_probing, quadratic_probing)
{
    std::unique_ptr<hash_probing> ptr = std::make_unique<quadratic_probing>(m, f1, c1, c2);
    CHECK_EQUAL(10, ptr->hash(k, 0));
}

TEST(hash_probing, double_hashing)
{
    std::unique_ptr<hash_probing> ptr = std::make_unique<double_hashing>(m, f1, f2);
    CHECK_EQUAL(10, ptr->hash(k, 0));
}