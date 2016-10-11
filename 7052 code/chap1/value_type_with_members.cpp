// value_type_with_members.cpp

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
