// writeline.cpp

using namespace System;

int main()
{
   // output without newline
   Console::Write("a");
   Console::Write("b");
   Console::Write("c");

   // newline alone
   Console::WriteLine();

   // output with format string
   Console::WriteLine("Fourscore and {0} years ago.", 7);

   // output with direct types
   Console::WriteLine(7);
   Console::WriteLine( 1.05);
   Console::WriteLine('A');
}
