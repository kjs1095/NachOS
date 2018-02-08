#include "syscall.h"

int main()
{ 
    PrintInt(Open(0));
    PrintInt(Open(""));
  
    // open non-existence file
    PrintInt(Open("openFile1095.txt"));

    // open file
    (void) Create("openFile1095.txt");
    PrintInt(Open("openFile1095.txt"));

    // open the same file
    PrintInt(Open("openFile1095.txt"));

    // open too many files
    (void) Create("f1.txt");
    (void) Create("f2.txt");
    (void) Create("f3.txt");
    (void) Create("f4.txt");

    PrintInt(Open("f1.txt"));
    PrintInt(Open("f2.txt"));
    PrintInt(Open("f3.txt"));
    PrintInt(Open("f4.txt"));

    return 0;
}
