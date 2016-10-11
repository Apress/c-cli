// exception_properties.cpp

using namespace System;

int main()
{

   try
   {
       bool error = true;
       // other code

       if (error)
       {
           throw gcnew Exception("XYZ");
       }
   }
   catch( Exception^ exception)
   {
       Console::WriteLine("Exception Source property {0}", exception->Source);
       Console::WriteLine("Exception StackTrace property {0}",
          exception->StackTrace);
       Console::WriteLine("Exception Message property {0}", exception->Message);
   }
}
