#include "syscall.h"

int main()
{
    char *s1 = "abcdefghijklmnopqrstuvwxyz";
    char *s2 = "zyxwvutsrqponmlkjihgfedcba";
    char *s3 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *s4 = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    char *s5 = "!@#$%^&*()-+=[]{};:?/|";
    int i = 1095;
    int n;
    for (n = 5; n <= 10; ++n) {
        PrintInt(n);
    }
    return 0;
}
