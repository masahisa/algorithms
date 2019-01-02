#include <CppUTest/TestHarness.h>
#include "doubly_linked_list.h"

TEST_GROUP(doubly_linked_list)
{
    doubly_linked_list list;
    void setup(){
        construct_doubly_linked_list(&list);
    }
    void teardown(){
        destruct_doubly_linked_list(&list);
    }
};

TEST(doubly_linked_list, construct_doubly_linked_list)
{
    CHECK_EQUAL(0, list.nil.key);
    POINTERS_EQUAL(&list.nil, list.nil.next);
    POINTERS_EQUAL(&list.nil, list.nil.prev);
}

TEST(doubly_linked_list, destruct_doubly_linked_list)
{
    destruct_doubly_linked_list(&list);
    CHECK_EQUAL(0, list.nil.key);
    POINTERS_EQUAL(&list.nil, list.nil.next);
    POINTERS_EQUAL(&list.nil, list.nil.prev);
}

TEST(doubly_linked_list, insert_doubly_linked_list)
{
    insert_doubly_linked_list(&list, 10);
    CHECK_EQUAL(0, list.nil.key);
    POINTERS_EQUAL(list.nil.prev, list.nil.next);
    POINTERS_EQUAL(list.nil.next, list.nil.prev);
    CHECK_EQUAL(10, list.nil.next->key);
    POINTERS_EQUAL(&list.nil, list.nil.next->prev);
    POINTERS_EQUAL(&list.nil, list.nil.next->next);
}

TEST(doubly_linked_list, search_doubly_linked_list)
{
    insert_doubly_linked_list(&list, 10);
    insert_doubly_linked_list(&list, 5);
    dll_node* node = search_doubly_linked_list(&list, 10);
    CHECK_EQUAL(10, node->key);
    dll_node* node1 = search_doubly_linked_list(&list, 5);
    CHECK_EQUAL(5, node1->key);
}

TEST(doubly_linked_list, delete_doubly_linked_list)
{
    insert_doubly_linked_list(&list, 10);
    dll_node* node = search_doubly_linked_list(&list, 10);
    delete_doubly_linked_list(&list, node);
    CHECK_EQUAL(0, list.nil.key);
    POINTERS_EQUAL(&list.nil, list.nil.next);
    POINTERS_EQUAL(&list.nil, list.nil.prev);
}