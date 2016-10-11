// generic_functions1.cpp
using namespace System;

generic < typename T>
void GenericFunction(T t)
{
   Console::WriteLine(t);
}

int main()
{
   int i;
   // Specify the type parameter.
   GenericFunction<int>( 200 );

   // Allow the type parameter to be
   // deduced.
   GenericFunction( 400 );
}
