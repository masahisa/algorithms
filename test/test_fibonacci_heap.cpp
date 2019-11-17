#include <CppUTest/TestHarness.h>
#include "fibonacci_heap.hpp"

TEST_GROUP(fibonacci_heap)
{
    void setup(){
        
    }
    void teardown(){

    }
};

TEST(fibonacci_heap, insert)
{
    fibonacci_heap<int> h;
    fib_heap_node<int> a;
    a.key = 10;
    h.insert(&a);
    CHECK_EQUAL(a.key, h.minimum()->key);
}

TEST(fibonacci_heap, unite)
{
    fibonacci_heap<int> h1;
    fibonacci_heap<int> h2;
    fib_heap_node<int> a1;
    fib_heap_node<int> a2;
    a1.key = 3;
    h1.insert(&a1);
    a2.key = 2;
    h2.insert(&a2);
    h1.unite(&h2);
    CHECK_EQUAL(a2.key, h1.minimum()->key);
    CHECK_EQUAL(2, h1.get_size());
}

TEST(fibonacci_heap, extract_min)
{
    fibonacci_heap<int> h;
    fib_heap_node<int> a1, a2, a3;
    a1.key = 10;
    h.insert(&a1);
    a2.key = 8;
    h.insert(&a2);
    a3.key = 6;
    h.insert(&a3);
    fib_heap_node<int>* min = h.extract_min();
    CHECK_EQUAL(a3.key, min->key);
    CHECK_EQUAL(2, h.get_size());
}

TEST(fibonacci_heap, decrease_key)
{
    fibonacci_heap<int> h;
    fib_heap_node<int> a1, a2, a3;
    a1.key = 10;
    h.insert(&a1);
    a2.key = 8;
    h.insert(&a2);
    a3.key = 6;
    h.insert(&a3);
    int new_key = 4;
    h.decrease_key(&a1, new_key);
    fib_heap_node<int>* min = h.minimum();
    CHECK_EQUAL(new_key, min->key);
}

TEST(fibonacci_heap, remove)
{
    fibonacci_heap<int> h;
    fib_heap_node<int> a1, a2, a3;
    a1.key = 10;
    h.insert(&a1);
    a2.key = 8;
    h.insert(&a2);
    a3.key = 6;
    h.insert(&a3);
    h.remove(&a3);
    fib_heap_node<int>* min = h.minimum();
    CHECK_EQUAL(a2.key, min->key);
}
