#include "open_address_hash_table.h"

void construct_open_address_hash_table(open_address_hash_table* t, int m, hash_probing* f)
{
    t->m = m;
    t->table = new int[m];
    for(int i = 0; i < m; i++){
        t->table[i] = HASH_NIL;
    }
    t->function = f;
}

void destruct_open_address_hash_table(open_address_hash_table* t)
{
    delete [] t->table;
}

int open_address_hash_table_insert(open_address_hash_table* t, int key)
{
    int i = 0;
    int j = 0;
    do{
        j = t->function->hash(key, i);
        if(t->table[j] == HASH_NIL || t->table[j] == HASH_DELETED){
            t->table[j] = key;
            return j;
        }
        i++;
    } while(i != t->m);
    return HASH_ERROR;
}

int open_address_hash_table_search(open_address_hash_table* t, int key)
{
    int i = 0;
    int j = 0;
    do{
        j = t->function->hash(key, i);
        if(t->table[j] == key){
            return j;
        }
        i++;
    } while(i != t->m || t->table[j] != HASH_NIL);
    return HASH_NIL;
}

int open_address_hash_table_delete(open_address_hash_table* t, int key)
{
    int i = open_address_hash_table_search(t, key);
    if(i != HASH_NIL){
        t->table[i] = HASH_DELETED;
        return i;
    }
    return HASH_ERROR;
}