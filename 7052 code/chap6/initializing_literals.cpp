// literal.cpp
using namespace System;

ref class C
{
   literal String^ name = "Bob";

   public:

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
}
