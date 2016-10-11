// arrays_sort_search.cpp
using namespace System;

int main()
{
   array<int>^ array1 = gcnew array<int>(10)
        { 122, 87, 99, 6, 45, 12, 987, 115, 0, 10 };

   Array::Sort(array1);

   for each (int i in array1)
   {
      // Output is sorted
      Console::Write("{0} ", i);
   }

   Console::WriteLine();

   // Search for one of the values
   int index = Array::BinarySearch( array1, 115);

   if (index >= 0 )
      Console::WriteLine( "Found {0} at position {1}.", array1[index], index );
   else
      Console::WriteLine(" Not Found. ");
}
