// detecting_clr.cpp
#include <stdio.h>
int main()
{
#ifdef _MANAGED
    System::Console::WriteLine("Must be compiling with /clr...");
#else
    printf("Not compiling with /clr.");
#endif
}
