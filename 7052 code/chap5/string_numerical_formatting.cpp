// string_numerical_formatting.cpp
using namespace System;

int main()
{
   String^ str;
   int i = -73000;
   double dbl = 1005.01;

   // Formats for floating-point types:

   str = String::Format("Currency format: {0:c2}", dbl);
   Console::WriteLine(str);

   str = String::Format("Scientific format: {0:e6}", dbl);
   Console::WriteLine(str);

   str = String::Format("Fixed-point format: {0:f6}", dbl);
   Console::WriteLine(str);

   str = String::Format("General format: {0:g6}", dbl);
   Console::WriteLine(str);

   str = String::Format("Number format: {0:n6}", dbl);
   Console::WriteLine(str);

   str = String::Format("Percent format: {0:p6}", dbl);
   Console::WriteLine(str);

   str = String::Format("Round-trip format: {0:r6}", dbl);
   Console::WriteLine(str);

   // Formats for integral types:

   str = String::Format("Decimal format: {0:d6}", i);
   Console::WriteLine(str);

   str = String::Format("General format: {0:g6}", i);
   Console::WriteLine(str);

   str = String::Format("Number format: {0:n0}", i);
   Console::WriteLine(str);

   str = String::Format("Hexadecimal format: {0:x8}", i);
   Console::WriteLine(str);
}
