#include "open_address_hash_table.h"
#include <cstdint>

void construct_open_address_hash_table(open_address_hash_table* t, int m, hash_probing* f)
{
    t->m = m;
    t->table = new int[m];
    for(int i = 0; i < m; i++){
        t->table[i] = INT32_MIN;
    }
    t->function = f;
}

void destruct_open_address_hash_table(open_address_hash_table* t)
{
    delete [] t->table;
}

bool open_address_hash_table_insert(open_address_hash_table* t, int key)
{
    int i = 0;
    while(i != t->m){
        int j = t->function->hash(key, i);
        if(t->table[j] == INT32_MIN){
            t->table[j] = key;
            return true;
        }
        i++;
    }
    return false;
}

int open_address_hash_table_search(open_address_hash_table* t, int key)
{
    int i = 0;
    while(i != t->m){
        int j = t->function->hash(key, i);
        if(t->table[j] == key){
            return j;
        }
        i++;
    }
    return INT32_MIN;
}

bool open_address_hash_table_delete(open_address_hash_table* t, int key)
{
    int i = open_address_hash_table_search(t, key);
    if(i != INT32_MIN){
        t->table[i] = INT32_MIN;
        return true;
    }
    return false;
}