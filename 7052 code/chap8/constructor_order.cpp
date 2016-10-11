// constructor_order.cpp
using namespace System;

class NativeClass
{
   public:

   NativeClass()
   {
      Console::WriteLine("NativeClass: Field constructor.");
   }
};

ref class ManagedClass
{
   public:

   ManagedClass()
   {
       Console::WriteLine("ManagedClass: Field constructor.");
   }
};

class NativeBase
{
   public:
     NativeBase()
     {
        Console::WriteLine("NativeBase: Base class constructor.");
     }
};

class NativeDerived : NativeBase
{
   NativeClass field;

   public:
     NativeDerived() : field()
     {
         Console::WriteLine("Native: Derived class constructor.");
     }
};

ref class ManagedBase
{
   public:
     ManagedBase()
     {
        Console::WriteLine("ManagedBase: Base class constructor.");
     }
};

ref class ManagedDerived : ManagedBase
{
   ManagedClass field;

   public:
     ManagedDerived() : field()
     {
         Console::WriteLine("ManagedDerived: Derived class constructor.");
     }
};

int main()
{
   NativeDerived nd;
   ManagedDerived md;
}
