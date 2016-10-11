// convert_and_parse.cpp

using namespace System;

int main()
{
   String^ str1 = "115";
   String^ str2 = "1.4e-12";

   // parse the string to get the integer value
   int i = Int32::Parse( str1 );

   // get the double value
   double x = Double::Parse( str2 );

   // use Convert class to convert the value
   int j = Convert::ToInt32( str1 );
   double y = Convert::ToDouble( str2 );

   // exception handlers may be used to catch parse failures and overflows

   try
   {
      int k = Int32::Parse("bad format");
   }
   catch(FormatException^ e)
   {
       Console::WriteLine("Exception occurred! {0}", e->Message );
   }
}
