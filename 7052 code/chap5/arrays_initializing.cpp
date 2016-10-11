// arrays_initializing.cpp
int main()
{

   // declare, create, and initialize a 1D native array
   int native_array[2] = { 10, 20 };

   // declare, create, and initialize a 1D managed array
   array<int>^ managed_array = gcnew array<int>(2) { 10, 20 };

   // declare, create, and initialize a 2D native array
   int native_array_2D[2][2] = { { 1, 0 }, { 0, 1 } };

   // declare, create, and initialize a 2D managed array
   array<int, 2>^ managed_array_2D = gcnew array<int, 2>(2, 2)
                    { { 1, 0 }, { 0, 1 } };

}
