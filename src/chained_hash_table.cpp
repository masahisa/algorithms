#include "chained_hash_table.h"
#include "hash_function.h"

void construct_chained_hash(chained_hash_table* t, int m, int (*hash_function)(int, int))
{
    t->m = m;
    t->table = new doubly_linked_list[m];
    for(int i = 0; i < t->m; i++){
        construct_doubly_linked_list(&t->table[i]);
    }
    t->h = hash_function;
}

void destruct_chained_hash(chained_hash_table* t)
{
    for(int i = 0; i < t->m; i++){
        destruct_doubly_linked_list(&t->table[i]);
    }
    delete [] t->table;
}

void chained_hash_insert(chained_hash_table* t, int key)
{
    int index = t->h(key, t->m);
    insert_doubly_linked_list(&t->table[index], key);
}

dll_node* chained_hash_search(chained_hash_table* t, int key)
{
    int index = t->h(key, t->m);
    return search_doubly_linked_list(&t->table[index], key);
}

void chained_hash_delete(chained_hash_table* t, dll_node* node)
{
    int index = t->h(node->key, t->m);
    delete_doubly_linked_list(&t->table[index], node);
}