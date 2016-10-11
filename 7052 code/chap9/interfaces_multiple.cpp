// interfaces_multiple.cpp

interface class IA { void f(); };

interface class IB { void g(); };

// Implement multiple interfaces:
ref class R : IA, IB
{
   public:
      virtual void f() {}
      virtual void g() {}
};
