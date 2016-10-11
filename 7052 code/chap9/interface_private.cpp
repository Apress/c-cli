// interface_private.cpp

interface class IInterface
{

   void f();
   int g();
};

ref class R : IInterface
{
      // The virtual keyword is required to implement the interface.
      virtual void f() sealed = IInterface::f
      { }

   public:
      virtual int g() { return 1; }
};

int main()
{
   R^ r = gcnew R();
   IInterface^ ir = r;
   ir->f();  // f may be called through the interface.

   // r->f();  // Error: f is private.
   r->g();     // OK
}
