#include "perfect_hashing.h"

secondary_hash_table::secondary_hash_table()
: m_{ 0 }
, a_{ 0 }
, b_{ 0 }
, f_{ 0, 0, 0, 0 }
, t_{  }
{

}

secondary_hash_table::secondary_hash_table(int m, int p, int a, int b)
: m_{ m }
, a_{ a }
, b_{ b }
, f_{ m, p, a, b }
, t_( m )
{
    for(int i = 0; i < m; i++){
        t_[i] = HASH_NIL;
    }
}

secondary_hash_table::~secondary_hash_table()
{

}

void secondary_hash_table::insert_key(int k)
{
    t_[f_.hash(k)] = k;
}

int* secondary_hash_table::search_key(int k)
{
    int index = f_.hash(k);
    if(t_[index] == k){
        return &t_[index];
    }
    return nullptr;
}

void secondary_hash_table::delete_key(int k)
{
    t_[f_.hash(k)] = HASH_NIL;
}

perfect_hashing::perfect_hashing(int m, int p, int a, int b)
: m_{ m }
, p_{ p }
, a_{ a }
, b_{ b }
, f_{ m, p, a, b }
, st_( m )
{

}

perfect_hashing::~perfect_hashing()
{

}

void perfect_hashing::set_secondary_hash_table(int i, int m, int a, int b)
{
    st_[i] = secondary_hash_table(m, p_, a, b);
}

void perfect_hashing::insert_key(int k)
{
    st_[f_.hash(k)].insert_key(k);
}

int* perfect_hashing::search_key(int k)
{
    return st_[f_.hash(k)].search_key(k);
}

void perfect_hashing::delete_key(int k)
{
    st_[f_.hash(k)].delete_key(k);
}