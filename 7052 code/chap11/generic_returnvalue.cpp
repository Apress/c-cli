// generic_return_value.cpp
using namespace System;

generic <typename T>
T f()
{
   return T();
}

int main()
{
  int i = f<int>();  // OK
  String^ s = f<String^>();  // OK
  double d = f(); // Error! Can't deduce type.
}
