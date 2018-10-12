#include "rod_cutting.h"
#include <cmath>
#include <cstdint>
#include <iostream>

int cut_rod(int* p, int n)
{
    if(n == 0){
        return 0;
    }

    int q = INT32_MIN;
    for(int i = 1; i <= n; i++){
        q = std::max(q, p[i] + cut_rod(p, n - i));
    }

    return q;
}

int memoized_cut_rod(int* p, int n)
{
    int* r = new int[n + 1];
    for(int i = 0; i < n + 1; i++){
        r[i] = INT32_MIN;
    }
    int q = memoized_cut_rod_aux(p, n, r);
    delete [] r;
    return q;
}

int memoized_cut_rod_aux(int* p, int n, int* r)
{
    if(r[n] >= 0){
        return r[n];
    }

    int q = 0;
    if(n == 0){
        q = 0;
    }
    else{
        q = INT32_MIN;
        for(int i = 1; i <= n; i++){
            q = std::max(q, p[i] + memoized_cut_rod_aux(p, n - i, r));
        }
    }
    r[n] = q;

    return q;
}

int bottom_up_cut_rod(int* p, int n)
{
    int* r = new int[n + 1];
    r[0] = 0;

    int q;
    for(int j = 1; j <= n; j++){
        q = INT32_MIN;
        for(int i = 1; i <= j; i++){
            q = std::max(q, p[i] + r[j - i]);
        }
        r[j] = q;
    }
    q = r[n];
    
    delete [] r;
    return q;
}

int bottom_up_cut_rod_with_cost(int* p, int n, int c)
{
    int* r = new int[n + 1];
    r[0] = 0;

    int q;
    for(int j = 1; j <= n; j++){
        q = p[j];
        for(int i = 1; i <= j - 1; i++){
            q = std::max(q, p[i] + r[j - i] - c);
        }
        r[j] = q;
    }
    q = r[n];
    
    delete [] r;
    return q;
}

void print_cut_rod_solution(int n, int* r, int* s)
{
    std::cout << "optimal decomposition of a rod of length " << n << " is ";
    while(n > 0){
        std::cout << s[n] << " ";
        n = n - s[n];
    }
    std::cout << std::endl;
}

int extended_bottom_up_cut_rod(int* p, int n)
{
    int* r = new int[n + 1];
    int* s = new int[n + 1];
    r[0] = 0;

    int q = extended_bottom_up_cut_rod_aux(p, n, r, s);
    print_cut_rod_solution(n, r, s);

    delete [] r;
    delete [] s;

    return q;
}

int extended_bottom_up_cut_rod_aux(int* p, int n, int* r, int* s)
{
    int q;
    for(int j = 1; j <= n; j++){
        q = INT32_MIN;
        for(int i = 1; i <= j; i++){
            if(q < p[i] + r[j - i]){
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
    return r[n];
}

int extended_memoized_cut_rod(int* p, int n)
{
    int* r = new int[n + 1];
    int* s = new int[n + 1];
    for(int i = 0; i < n + 1; i++){
        r[i] = INT32_MIN;
        s[i] = 0;
    }

    int q = extended_memoized_cut_rod_aux(p, n, r, s);
    print_cut_rod_solution(n, r, s);

    delete [] r;
    delete [] s;

    return q;
}

int extended_memoized_cut_rod_aux(int* p, int n, int* r, int* s)
{
    if(r[n] >= 0){
        return r[n];
    }

    int q = 0;
    if(n == 0){
        q = 0;
    }
    else{
        q = INT32_MIN;
        for(int i = 1; i <= n; i++){
            int t = p[i] + extended_memoized_cut_rod_aux(p, n - i, r, s);
            if(t > q){
                q = t;
                s[n] = i;
            }
        }
    }
    r[n] = q;

    return q;
}