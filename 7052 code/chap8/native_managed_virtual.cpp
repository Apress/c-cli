// native_managed_virtual.cpp

class NativeBase
{
   public:

   NativeBase()
   {
      f_virt();
   }

   virtual void f_virt()
   {
      System::Console::WriteLine("NativeBase::f_virt");
   }
};

class NativeDerived : public NativeBase
{
   public:

   NativeDerived()
   {
      f_virt();
   }

   virtual void f_virt()
   {
      System::Console::WriteLine("NativeDerived::f_virt");
   }
};

ref class ManagedBase
{
   public:

   ManagedBase()
   {
      f_virt();
   }

   virtual void f_virt()
   {
      System::Console::WriteLine("ManagedBase::f_virt");
   }
};

ref class ManagedDerived : ManagedBase
{
   public:

   ManagedDerived()
   {
      f_virt();
   }

   virtual void f_virt() override
   {
      System::Console::WriteLine("ManagedDerived::f_virt");
   }
};

int main()
{
   NativeDerived nd;
   ManagedDerived rd;
}
