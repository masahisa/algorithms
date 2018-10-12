#include "fibonacci.h"

int bottom_up_fibonacci(int n)
{
    int fi_2 = 0;
    int fi_1 = 1;

    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }

    int fi = 0;
    for(int i = 2; i <= n; i++){
        fi = fi_1 + fi_2;
        fi_2 = fi_1;
        fi_1 = fi;
    }
    return fi;
}