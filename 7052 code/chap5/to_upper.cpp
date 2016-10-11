// to_upper.cpp
// Convert text read from stdin to uppercase and write to stdout
using namespace System;

int main()
{
   String^ str;
   while ((str = Console::ReadLine()) != nullptr)
   {
      Console::WriteLine( str->ToUpper() );
   }
}
