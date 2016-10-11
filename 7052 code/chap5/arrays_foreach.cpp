// arrays_foreach.cpp
using namespace System;

int main()
{
   array<String^>^ stringArray = gcnew array<String^>
       { "one", "two", "three", "four", "five" };

   for each (String^ str in stringArray)
   {
      Console::WriteLine(str);
   }
}
