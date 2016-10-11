// arraylist.cpp
using namespace System;
using namespace System::Collections;

int main()
{
   ArrayList^ array_list = gcnew ArrayList();

   array_list->Add("apple");
   array_list->Add("banana");

   // iterate using the for each operator
   for each (String^ s in array_list)
   {
       Console::WriteLine( s );
   }

   // iterate using indexing

   for (int i = 0; i < array_list->Count; i++)
   {
       Console::WriteLine("{0} {1}", i, array_list[i]);
   }
}
