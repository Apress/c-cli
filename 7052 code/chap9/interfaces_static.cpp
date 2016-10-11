// interfaces_static.cpp
using namespace System;

interface class IA
{
   static int i = 6;
   static const int j = 100;

   static void f()  { Console::WriteLine("IA::f " + i); }
};

ref class A : IA
{
   public:

   static void f() { Console::WriteLine("A::f " + IA::j); }
};

int main()
{
   A^ a = gcnew A();
   IA^ ia = a;
   ia->f();     // Call IA::f through interface handle.
   a->f();      // Call A::f through object handle.
   IA::f();     // Call IA::f.
   A::f();      // Call A::f.
   a->IA::f();  // Call IA::f
}
