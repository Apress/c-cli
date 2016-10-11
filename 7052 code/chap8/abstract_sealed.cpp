// abstract_sealed.cpp
using namespace System;

ref class A abstract sealed
{
   static int i = 1;
   static int j = 2;
   public:
     static A() { Console::WriteLine("A::A()"); }
     static void f() { Console::WriteLine("A::f " + i); }
     static void g() { Console::WriteLine("A::g " + j); }
};

int main()
{
   A::f();
   A::g();
}
