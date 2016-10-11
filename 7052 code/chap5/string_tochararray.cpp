// string_tochararray.cpp
using namespace System;

int main()
{
   String^ str = "A quick sly fox jumped over the lazy brown dog.";

   array<Char>^ character_array = str->ToCharArray();

   // Prints the original string.
   Console::WriteLine( str);

   // Modify characters in the character array.
   for (int i = 0; i < character_array->Length; i++)
   {
      if ( character_array[i] >= L'a' && character_array[i] <= 'z')
      {
        character_array[i] -= (L'a' - L'A');
      }
   }

   // Convert back to a String using the String constructor
   // that takes a Unicode character array.
   str = gcnew String(character_array);

   // Prints the modified string:
   // A QUICK SLY FOX JUMPED OVER THE LAZY BROWN DOG.
   Console::WriteLine( str);
}
