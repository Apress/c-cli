// finalizers_and_inheritance.cpp
using namespace System;

ref class Base
{
   public:
     Base() { }
     ~Base() {  Console::WriteLine("~Base"); this->!Base(); }
     !Base() {  Console::WriteLine("!Base"); }
};

ref class Derived : Base
{
   public:
     Derived() { }
     ~Derived() {  Console::WriteLine("~Derived"); this->!Derived(); }
     !Derived() {  Console::WriteLine("!Derived"); }
};

void F()
{
   // Use stack semantics to create the object.
   Derived d;
}

void G()
{
   // Use the GC heap to create the object.
   Derived^ dh = gcnew Derived();

   // If you want to call the destructor for this object,
   // call it explicitly here, or delete the handle.
}

int main()
{
   // Since the destructor gets called, the finalizers
   // also get called when F goes out of scope.
   F();
   G();
   Console::WriteLine("Collecting after G()");
   // Force a collection of dh: finalizer only, not
   // the destructor.
   GC::Collect();
}
