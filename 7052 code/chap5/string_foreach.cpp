// string_foreach.cpp
using namespace System;

int main()
{
   String^ str1 = "Ode on a Grecian Urn";

   for each (Char ch in str1)
   {
      Console::Write(ch);
   }
   Console::WriteLine();
}
