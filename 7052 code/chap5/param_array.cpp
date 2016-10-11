// param_array.cpp
using namespace System;

// Total takes at least one int and a variable
// number of subsequent integers that are wrapped
// into a managed array
int Total( int a, ... array<int>^ varargs)
{
   int tot = a;
   for each ( int i in varargs)
   {
      tot += i;
   }
   return tot;
}

int main()
{
   int sum1 = Total(100, 200, 350);
   Console::WriteLine("First total: {0}", sum1);

   int sum2 = Total(1, 2, 3, 4, 5, 6, 7, 8);
   Console::WriteLine("Second total: {0}", sum2);
}
