// interface_name_collision.cpp
using namespace System;

interface class I1 { void f(); };

interface class I2 { void f(); };

ref class R : I1, I2
{
   public:

   virtual void f()
   { Console::WriteLine("R::f"); }
};

int main()
{
   R^ r = gcnew R();
   r->f();  // R::f() implements both I1's f and I2's f
}
