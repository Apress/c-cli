// interior_ptr.cpp
using namespace System;

ref struct S
{
   array<int>^ array1;

   S()
   {
       array1 = gcnew array<int>(10)
          { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
   }

   void f()
   {
      interior_ptr<int> p = &array1[0];
      for (int i = 0; i < 10; i++)
      {
          Console::WriteLine(*p++);
      }
   }
};

