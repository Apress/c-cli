// literal_public.cpp
using namespace System;

ref class C
{
   public:

   literal String^ name = "Bob";

   C()
   {
       Console::WriteLine(name);
   }

   void Print()
   {
       Console::WriteLine(name);
   }
};

int main()
{
   C^ c = gcnew C();
   c->Print();

   // Access through the class:
   Console::WriteLine( C::name );
}
