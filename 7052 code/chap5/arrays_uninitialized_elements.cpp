// arrays_uninitialized_elements.cpp
using namespace System;

int main()
{
   array<String^>^ stringArray = gcnew array<String^>(5)
       { "one", "two" };

   for (int i = 0; i < stringArray->Length; i++)
   {
      Console::WriteLine( stringArray[i] );
   }

   Console::WriteLine("End.");
}
