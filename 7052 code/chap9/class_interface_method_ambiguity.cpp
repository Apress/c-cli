// class_interface_method_ambiguity.cpp
using namespace System;

interface class IA
{
   void f();
};

ref class A : IA
{
   public:

   // Note that new is not used here.
   void f()
   {
     Console::WriteLine("A::f");
   }
   // Explicit implementation syntax
   virtual void fIA() = IA::f
   {
     Console::WriteLine("A::fIA implementing IA::f");
   }
};

int main()
{
   A^ a = gcnew A();
   IA^ ia = a;
   ia->f();
   a->f();
}
