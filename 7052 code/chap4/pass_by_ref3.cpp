// pass_by_ref3.cpp
// This example requires some careful thought.
// Can you figure out what the final output
// will be?
using namespace System;

ref struct R
{
   property int A;
   R(int a) { this->A = a; }
};

// Takes a reference to a handle. This function
// sets the property value on the object, then
// overwrites the object!
// Will the object in the calling scope
// have the value 3, or 5, or will it retain its
// original value?
void reset_handle(R^% r)
{
   r->A = 3;
   r = gcnew R(5);
}

int main()
{
   R r_stack(1); // stack semantics
   R^ r_heap = gcnew R(2); // heap semantics

   reset_handle(%r_stack);  // use % to create a handle
   reset_handle(r_heap);

   Console::WriteLine("Final value, stack semantics: {0}", r_stack.A);
   Console::WriteLine("Final value, heap semantics: {0}", r_heap->A);
}
