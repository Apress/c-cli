// greeting.cpp
using namespace System;

value struct Greeting
{
   String^ greeting;
   Char punctuator;

   void PrintGreeting(String^ name)
   {
       Console::WriteLine(greeting + name + punctuator);
   }
};

int main(array<String^>^ args)
{
   Greeting greet;
   greet.greeting = "Hi ";
   greet.punctuator = '!';

   if (args->Length < 1)
   {
      Console::WriteLine("Enter names on the command line, like this:"
                         " greeting <name1> <name2> ...");
      Console::WriteLine("Use quotes around names with spaces.");
      return 1;
   }

   for (int i = 0; i < args->Length; i++)
   {
      greet.PrintGreeting(args[i]);
   }

   greet.greeting = "Hello, ";
   greet.punctuator = '.';

   for each (String^ s in args)
   {
      greet.PrintGreeting(s);
   }
}
