#include "randomization.h"
#include <random>
#include <cmath>
#include <algorithm>

int random_int(int min, int max)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(engine);
}

void permute_by_sorting(int* a, int size)
{
    int* p = new int[size];
    for(int i = 0; i < size; i++){
        p[i] = random_int(0, static_cast<int>(std::pow(static_cast<double>(size - 1), 3.0)));
    }

    // sort array using p as sort keys in O(n^2) time
    std::sort(a, a + size, [&](const int& x, const int& y) -> bool { return p[x] < p[y]; });

    delete [] p;
}

void randomize_in_place(int* a, int size)
{
    for(int i = 0; i < size; i++){
        std::swap(a[i], a[random_int(i, size - 1)]);
    }
}