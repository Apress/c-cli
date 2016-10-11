// destructors_and_inheritance.cpp
using namespace System;

ref class Base
{
   public:
     Base() {}
     ~Base() {  Console::WriteLine("~Base"); }
};

ref class Derived : Base
{
   public:
     Derived() { }
     ~Derived() {  Console::WriteLine("~Derived"); }
};

// The destructor will be called at the end of main.
int main()
{
   Derived d;
}
