#include "syscall.h"

int main()
{   
    int n;
    for (n = 20; n > 15; --n) {
        PrintInt(n);
    }
    return 0;
}
