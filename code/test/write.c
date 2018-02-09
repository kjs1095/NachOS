#include "syscall.h"

int main()
{
    char* data = "1095";
    int fd = 0, fd_s, fd_l, fd_n;
    PrintInt(Write(data, 4, -1)); 
    PrintInt(Write(data, 4, 0));
 
    Create("writeFile1095.txt");
    fd = Open("writeFile1095.txt");

    PrintInt(Write(0, 0, fd));
    PrintInt(Write(0, -1, fd));
    
    PrintInt(Write("", -1, fd));
    PrintInt(Write("", 0, fd));

    PrintInt(Write(data, 4, fd));
    
    Create("short");
    fd_s = Open("short");
    
    PrintInt(Write(data, 1, fd_s));

    Create("long");
    fd_l = Open("long");
        
    PrintInt(Write(data, 1095, fd_l));

    Create("neg");
    fd_n = Open("neg");

    PrintInt(Write(data, -1, fd_n));

    Close(fd);
    return 0;
}
