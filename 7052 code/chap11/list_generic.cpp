// list_generic.cpp
using namespace System;
using namespace System::Collections::Generic;

int main()
{
   List<String^>^ list = gcnew List<String^>();
   // or IList<String^>^ list = gcnew List<String^>();

   list->Add("apple");
   list->Add("banana");

   // Iterate using the for each operator.
   for each (String^ s in list)
   {
       Console::WriteLine( s );
   }

   // Iterate using indexing.

   for (int i = 0; i < list->Count; i++)
   {
       Console::WriteLine("{0} {1}", i, list[i]);
   }
}
