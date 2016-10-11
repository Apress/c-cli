// string_operator_plus.cpp
using namespace System;

int main()
{
   String ^hrs = "Hours", ^mins = "Minutes";
   wchar_t separator = ':';
   int minutes = 56, hours = 1;

   Console::WriteLine( hrs + separator + " " + hours + "\n" + mins +
                       separator + " " + minutes);
}
