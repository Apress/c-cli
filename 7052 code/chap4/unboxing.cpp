// unboxing.cpp
using namespace System;

Object^ f(Object^ obj)
{
   Console::WriteLine("In f, with " + obj->ToString() + ".");
   return obj;
}

int main()
{
   int i = 1;
   int j = safe_cast<int>( f(i) );  // cast back to int to unbox the object

}
