// stringbuilder.cpp

using namespace System;
using namespace System::Text;

int main()
{
   // Construct a StringBuilder string with initial contents
   // "C" and initial capacity 30.
   StringBuilder^ sb = gcnew StringBuilder("C", 30);

   sb->Append(gcnew array<Char>{'+','+'});

   sb->Append("/CLI.");

   sb->Insert(0, "I love ");

   sb->Replace(".","!");

   Console::WriteLine( sb->ToString() );
}
