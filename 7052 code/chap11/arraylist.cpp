// arraylist.cpp
using namespace System;
using namespace System::Collections;

int main()
{
   ArrayList^ array_list = gcnew ArrayList();

   array_list->Add(1);

   array_list->Add("test");

   // Iterate using the for each operator.
   for each (Object^ o in array_list)
   {
       Console::WriteLine( o->ToString() );
   }

   // Iterate using indexing.

   for (int i = 0; i < array_list->Count; i++)
   {
       Console::WriteLine("{0} {1}", i, array_list[i]);
   }
}
