// array_exception.cpp
using namespace System;

int main()
{
   int i;
   array<int>^ array1 = { 0, 1, 2};

   try
   {
      i = array1[3];
   }
   catch(IndexOutOfRangeException^ e)
   {
      Console::WriteLine( "{0}, {1}" , e->ToString(), e->Message);
   }
}
