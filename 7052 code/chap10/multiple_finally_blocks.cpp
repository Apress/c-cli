// multiple_finally_blocks.cpp

using namespace System;

int main()
{
   try
   {
       Console::WriteLine("Outer try");

       try
       {
           Console::WriteLine("Inner try");
           throw gcnew Exception("XYZ");

       }
       catch( Exception^ exception)
       {
           Console::WriteLine("Inner catch");
       }
       finally
       {
           Console::WriteLine("Inner finally");
       }
   }
   catch(Exception^ exception)
   {
        Console::WriteLine("Outer catch");
   }
   finally
   {
        Console::WriteLine("Outer finally");
   }
}
