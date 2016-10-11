// class_constraint.cpp
using namespace System;
ref class B
{
   public:
      virtual void f() {}
};

generic <typename T> where T : B
ref class G
{
    T t;

    public:
       G(T t_in) : t(t_in)
       {
           // For this example, C::f is
           // called.
           t->f();
       }
};

ref class C : B
{
   public:
       virtual void f() override
       {
           Console::WriteLine("C::f");
       }
};

int main()
{
     G<C^>^ r = gcnew G<C^>(gcnew C());
}
