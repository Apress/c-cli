// base_and_interface.cpp

using namespace System;

ref class B
{
   public:

      virtual void f() { Console::WriteLine("B::f"); }
      virtual void g() { Console::WriteLine("B::g"); }
};

interface class I
{
   void f();
   void g();
};

ref class C : B, I
{
   public:

   // f implements I::f but doesn't override B::f
   virtual void f() new
   {
      Console::WriteLine("C::f");
   }
   // g overrides B::g AND implements I::g
   virtual void g() override
   {
      Console::WriteLine("C::g");
   }
};

int main()
{
   B^ b = gcnew B();
   C^ c = gcnew C();
   I^ i = c;

   // behavior with the new specifier
   b->f(); // calls B::f
   c->f(); // calls C::f
   i->f(); // calls C::f since C::f implements I::f

   B^ bc = c;  // b pointing to instance of C
   bc->f(); // calls B::f since C::f is unrelated

   // behavior with the override specifier
   b->g();  // calls B::g
   c->g();  // calls C::g
   i->g();  // calls C::g since C::g implements I::g

   bc->g(); // calls C::g since C::g overrides B::g
}
