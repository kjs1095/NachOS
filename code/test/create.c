#include "syscall.h"
int main()
{
    char* fileName1 = "createFile1095.txt";
    char fileName2[4]; // "abc"
    char fileName3[4]; // empty string
    char fileName4[4]; // null 
    int i;
    for (i = 0; i < 4; ++i)
        fileName2[i] = i + 'a';
    fileName2[3] = '\0';

    fileName3[0] = '\0';

    PrintInt(Create(fileName1));
    PrintInt(Create(""));
    PrintInt(Create(0));
    PrintInt(Create(fileName1));
    PrintInt(Create(fileName2));
    PrintInt(Create(fileName3));
    PrintInt(Create(fileName4));
    return 0;
}
