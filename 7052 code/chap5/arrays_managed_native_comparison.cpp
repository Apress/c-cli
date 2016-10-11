// arrays_managed_native_comparison.cpp
#include <iostream>
using namespace std;

int main()
{
   // native 1D array
   int native_array_1D[10];

   // managed 1D array
   array<int>^ managed_array_1D = gcnew array<int>(10);

   for (int i = 0; i < 10; i++)
   {
      native_array_1D[i] = i*i;
      cout << native_array_1D[i] << " ";
      managed_array_1D[i] = native_array_1D[i];
      cout << managed_array_1D[i] << " ";
   }

   cout << endl;
}
