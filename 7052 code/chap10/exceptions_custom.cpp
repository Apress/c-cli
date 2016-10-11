// exceptions_custom.cpp
using namespace System;

ref class MyException : Exception
{
   public:

    virtual property String^ Message
    {
        String^ get() override
        {
           return "You must supply a command-line argument.";
        }
    }
};

int main(array<String^>^ args)
{
     try
     {
         if (args->Length < 1)
         {
            throw gcnew MyException();
         }
         throw gcnew Exception();
     }
     // The first catch blocks are the specific exceptions that
     // you are looking for.
     catch (MyException^ e)
     {
           Console::WriteLine("MyException occurred! " + e->Message);
     }
     // You may also catch other exceptions with multiple try blocks,
     // although it's better.
     catch (Exception^ exception)
     {
           Console::WriteLine("Unknown exception!");
     }
}
