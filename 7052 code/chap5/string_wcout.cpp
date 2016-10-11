// string_wcout.cpp
#include <vcclr.h>
#include <iostream>

using namespace std;
using namespace System;

int main()
{
   String^ s = "Testing String conversion to iostream.";

   pin_ptr<const wchar_t> ptr = PtrToStringChars(s);
   wcout << static_cast<const wchar_t*>( ptr ) << endl;
}
