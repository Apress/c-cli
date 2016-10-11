// arrays_copy.cpp
using namespace System;

int main()
{
   array<int>^ array1 = { 0, 1, 2};

   // shallow copy creates another name for the array
   array<int>^ array2 = array1;

   array2[0] = 100;

   // This prints "100" since array2 is a synonym of array1
   Console::WriteLine( "{0}", array1[0] );

   array<int>^ array3 = gcnew array<int>(3);
   Array::Copy(array1, array3, array1->Length);

   // Change a value in the new copy of the array
   array3[0] = 200;

   // This prints "100 1 2" since the old array was not affected
   Console::WriteLine( "{0} {1} {2}", array1[0], array1[1], array1[2]);
}
