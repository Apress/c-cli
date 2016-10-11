// array_equality_test.cpp
using namespace System;

// This function tests the equality of two 1D
// arrays of int.
bool ReallyEquals(array<int>^ a, array<int>^ b)
{
   if (a->Length != b->Length)
       return false;

   // element-by-element comparison
   for (int i = 0; i < a->Length; i++)
   {
       if (a[i] != b[i]) return false;
   }
   return true;
}

int main()
{
   array<int>^ ai1 = gcnew array<int> { 1, 2 };
   array<int>^ ai2 = gcnew array<int> { 1, 2 };

   // are these arrays equal?
   if ( ai1 == ai2 )
   {
       Console::WriteLine("The arrays are equal using the == operator.");
   }
   if (ai1->Equals(ai2) )
   {
       Console::WriteLine("The arrays are equal using the Equals method.");
   }
   if (ReallyEquals(ai1, ai2))
   {
       Console::WriteLine(
        "The arrays are equal using element-by-element comparison.");
   }
 }
