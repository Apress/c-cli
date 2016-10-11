// arrays_length.cpp
using namespace System;

int main()
{
   array<String^>^ string_array =
           gcnew array<String^>(2) { "first", "second" } ;

   for (int i = 0; i < string_array->Length; i++)
   {
      Console::WriteLine( string_array[i] );
   }
}
