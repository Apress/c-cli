// generic_functions2.cpp
using namespace System;

generic < typename T>
void GenericFunction(array<T>^ array_of_t)
{
   for each (T t in array_of_t)
   {
      Console::WriteLine(t);
   }
}

int main()
{
   array<String^>^ array_of_string;

   array_of_string = gcnew array<String^>
    { "abc", "def", "ghi" };

   // Allow the type parameter to be
   // deduced.
   GenericFunction( array_of_string );
}
