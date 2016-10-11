// string_equality.cpp
using namespace System;

int main()
{
   String^ str1 = "1";
   String^ str2 = "1";
   String^ str3 = str1;

   // All of the following tests result in True, since
   // the == operator is equivalent to the Equals method.
   if (str1 == str2)
   {
      Console::WriteLine(" str1 == str2" );
   }
   if (str1 == str3)
   {
      Console::WriteLine(" str1 == str3" );
   }
   if (str1->Equals(str2))
   {
      Console::WriteLine(" str1 Equals str2" );
   }
   if (str1->Equals(str3))
   {
      Console::WriteLine(" str1 Equals str3");
   }

   // ReferenceEquals compares the handles, not the actual
   // string. The results are implementation dependent,
   // since if the compiler creates a single string representation
   // for both string literals, as is the case here, this will resolve
   // true.
   if (String::ReferenceEquals(str1, str2))
   {
      Console::WriteLine(" str1 ReferenceEquals str2");
   }
   if (String::ReferenceEquals(str1, str3))
   {
      Console::WriteLine(" str1 ReferenceEquals str3");
   }
}
