#include "syscall.h"

int main()
{   
    int fd[4], i, tmpFd;
    char* name[4] = {"f1", "f2", "f3", "f4"};
    // illegal file descriptor
    Close(-1);
    // empty entry
    Close(0);

    // close a file    
    Create("closeFile1095.txt");
    tmpFd = Open("closeFile1095.txt");
    Close(tmpFd);

    for (i = 0; i < 4; ++i)
        Create(name[i]);
    for (i = 0; i < 4; ++i)
        fd[i] = Open(name[i]);

    // close a file should free an entry
    PrintInt(Open("closeFile1095.txt"));    // -1
    Close(fd[2]);
    PrintInt(Open("closeFile1095.txt"));    // 2
    
    PrintInt(Open(name[2]));    // -1

    return 0;
}
