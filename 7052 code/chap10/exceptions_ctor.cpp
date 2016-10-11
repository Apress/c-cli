// exceptions_ctor.cpp

using namespace System;

// the type of the member
ref class Class1
{
    public:

    Class1()
    {
       // Assume a fatal problem has occurred here.
       throw gcnew Exception();
    }
};

ref class A
{

   Class1^ c1;
   Class1^ c2;

   public:

   A()
   {
       //  c1 has a problem; it throws an exception.
       c1 = gcnew Class1();

       // c2 never gets created.
       c2 = gcnew Class1();
   }

   void F() { Console::WriteLine("Testing F"); }

   ~A() // Never gets called, even if A is created with stack semantics
   {
       Console::WriteLine("A::~A()");
   }

   !A()  // Gets called for partially constructed object
   {
       Console::WriteLine("A::!A()");
       // Don't try to use C2 here without checking for null first.
   }

};

int main()
{
   A a;
   a.F();  // never reached
}
