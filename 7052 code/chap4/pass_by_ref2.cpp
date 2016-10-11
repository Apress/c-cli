// pass_by_ref2.cpp
// This example illustrates that a stack semantics
// reference type can't be redirected by a function
// that operates on references to handles.
using namespace System;

ref struct R
{
   property int A;
   R(int a) { this->A = a; }
};

// Takes a reference to a handle
void reset_handle(R^% r)
{
   r = gcnew R(5);
}

int main()
{
   R r(2); // stack semantics
   reset_handle(%r);  // use % to create a handle

   // The output is 2, since the handle passed to f
   // was a temporary one, so it didn't get changed by
   // the function f.

   Console::WriteLine("Value: {0}", r.A);
}
