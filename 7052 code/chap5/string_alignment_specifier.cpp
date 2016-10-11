// string_alignment_specifier.cpp
using namespace System;

int main()
{
   // The format string is interpreted as follows:
   // { 0, -30 } 30 characters in width, left-justified
   // { 1, 10 } 10 characters in width, right-justified
   // { 2, 10:c2 } 10 characters in width, currency with 2 decimal places
   String^ format = "{0,-30}{1,10}{2,10:c2}";
   String^ header = String::Format(format, "Item", "Quantity", "Price");
   String^ str1 = str1->Format(format, "Matches, Strike Anywhere", 10, 0.99);
   String^ str2 = str2->Format(format, "Gloves", 1, 12.50);
   String^ str3 = str3->Format(format, "Iodine", 1, 4.99);

   Console::WriteLine(header);
   Console::WriteLine(str1 + "\n" + str2 + "\n" + str3);
}
