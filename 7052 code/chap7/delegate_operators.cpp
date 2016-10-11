// delegate_operators.cpp

using namespace System;

delegate void MyDelegate();

ref class R
{
   public:

   void f() { Console::WriteLine("R::f"); }
   void g() { Console::WriteLine("R::g"); }
};

int main()
{
   MyDelegate^ d;
   R^ r = gcnew R();

   d += gcnew MyDelegate(r, &R::f);
   d += gcnew MyDelegate(r, &R::g);

   d->Invoke();

   d -= gcnew MyDelegate(r, &R::g);

   // Use operator() instead of calling Invoke
   d();
}
