// dictionary.cpp
using namespace System;
using namespace System::Collections::Generic;

int main()
{
   IDictionary<String^, String^>^ dict;
   dict = gcnew Dictionary<String^, String^>();

   // The add method takes the key and the value.
   dict->Add("hat", "head adornment");
   dict->Add("hot", "at a high temperature");
   dict->Add("hit", "to strike");

   // Use the KeyValuePair generic class when using the
   // for each statement.
   for each (KeyValuePair<String^, String^>^ pair in dict)
   {
      Console::WriteLine(" {0}: {1}", pair->Key, pair->Value);
   }

   // The remove method takes the key as an argument.
   dict->Remove("hat");

   // Use the KeyValuePair generic class when using the
   // for each statement.
   for each (KeyValuePair<String^, String^>^ pair in dict)
   {
      Console::WriteLine(" {0}: {1}", pair->Key, pair->Value);
   }
}
