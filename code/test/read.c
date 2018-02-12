#include "syscall.h"

int main()
{
    OpenFileId fd = Open("filesys/test/big");
    OpenFileId fd1 = Open("nonExist.txt");
    char data[130];

    PrintInt(Read(data, 130, fd1));

    PrintInt(Read(data, 0, fd));
    PrintInt(Read(data, -1, fd));
// TODO code segment should be read only
//    PrintInt(Read(0, 130, fd));

    PrintInt(Read(data, 130, fd));
    Create("result");
    Write(data, 130, Open("result"));
    
    return 0;
}
