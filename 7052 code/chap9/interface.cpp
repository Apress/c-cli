interface class IInterface
{
   void f();
   int g();
};

ref class R : IInterface
{
   public:
      // The virtual keyword is required to implement the interface method.
      virtual void f() { }

      virtual int g() { return 1; }
};
