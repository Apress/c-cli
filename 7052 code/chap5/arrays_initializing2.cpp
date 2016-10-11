// arrays_initializing2.cpp
int main()
{
   // initialization without gcnew

   array<int>^ array_int1 = { 0, 1, 2 };

   // initialization with gcnew (no equal sign is used)
   // here, the size is omitted and determined by the three
   // elements in the initializer list
   array<int>^ array_int2 = gcnew array<int> { 0, 1, 2 };

   // You can use variables in the initializer list

   int i = 1, j = 2, k = 3;
   array<int>^ array_int3 = { i, j, k };
}
