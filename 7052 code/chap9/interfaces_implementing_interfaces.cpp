// interfaces_implementing_interfaces.cpp

interface class IA { void f(); };

interface class IB : IA { void g(); };

ref class R : IB
{
   public:
      virtual void f() {}
      virtual void g() {}
};
