// explicit_interface_implementation.cpp
using namespace System;

interface class I1 { void f(); };

interface class I2 { void f(); };

ref class R : I1, I2
{
   public:

   virtual void f1() = I1::f
   {
      Console::WriteLine("R::f1 == I1::f");
   }

   virtual void f2() = I2::f
   {
      Console::WriteLine("R::f2 == I2::f");
   }
};

int main()
{

   R^ r = gcnew R();

   I1^ i1 = r;
   I2^ i2 = r;

   r->f1();       // OK -- call through the object.
   r->f2();       // OK -- call through the object.

   // r->f();     // Error: f is not a member of R.

   i1->f();       // OK -- call f1.
   i2->f();       // OK -- call f2.

   // r->I1::f();    // Compiler error: "direct call will fail at runtime".
   // r->I1::f1();   // Error: f1 is not a member of I1.
}
