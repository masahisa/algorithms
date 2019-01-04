#include "hash_probing.h"

hash_probing::hash_probing(int m)
: m_{ m }
{

}

hash_probing::~hash_probing()
{

}

linear_probing::linear_probing(int m, hash_function* f)
: hash_probing(m)
, f_{ f }
{

}

linear_probing::~linear_probing()
{

}

int linear_probing::hash(int k, int i)
{
    return (f_->hash(k) + i) % m_;
}

quadratic_probing::quadratic_probing(int m, hash_function* f, int c1, int c2)
: hash_probing(m)
, f_{ f }
, c1_{ c1 }
, c2_{ c2 }
{

}

quadratic_probing::~quadratic_probing()
{

}

int quadratic_probing::hash(int k, int i)
{
    return (f_->hash(k) + c1_ * i + c2_ * i * i) % m_;
}

double_hashing::double_hashing(int m, hash_function* f1, hash_function* f2)
: hash_probing(m)
, f1_{ f1 }
, f2_{ f2 }
{

}

double_hashing::~double_hashing()
{

}

int double_hashing::hash(int k, int i)
{
    return (f1_->hash(k) + i * f2_->hash(k)) % m_; 
}