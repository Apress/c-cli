// constructor_inheritance.cpp
using namespace System;

ref class MyBase
{
    int data;
  public:
    MyBase() { Console::WriteLine("MyBase::MyBase()"); }
    MyBase(int data_in) : data(data_in)
    { Console::WriteLine("MyBase::MyBase(int)"); }
};

ref class Derived : MyBase
{
   public:
     // Invoke the base class constructor.
     Derived(int data) : MyBase(data)
     { Console::WriteLine("Derived::Derived(int)"); }

};

int main()
{
    // Derived d; // illegal: ctor w/o args not inherited
    MyBase b;
    Derived d(100);
}
