// multiple_generic_parameters.cpp
using namespace System;

generic <typename T, typename U>
void F(T t, array<U>^ a, int i, String^ s)
{
   // ...
}
