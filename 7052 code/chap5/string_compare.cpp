// string_compare.cpp
using namespace System;

int main()
{
   String^ str1 = "cat";
   String^ str2 = "cab";

   if (str1->CompareTo( str2 ) < 0)
   {
       Console::WriteLine(str1 + " is less than " + str2);
   }
      // For variety, use the static method.
   else if ( String::Compare(str1, str2) > 0 )
   {
       Console::WriteLine("{0} is less than {1}", str2, str1);
   }

   else if ( str1->CompareTo( str2 ) == 0)
   {
       Console::WriteLine("The strings are both equal, with value {0}.", str1);
   }
}
