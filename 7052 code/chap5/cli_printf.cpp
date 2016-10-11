// cli_printf.cpp

using namespace System;
#include <stdio.h>

int main()
{
   String^ str = "managed string";

   // The string is automatically converted to a
   // char array for printf_s
   printf_s("%s", str );
}
