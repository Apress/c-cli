// obsolete.cpp
using namespace System;

ref class C
{
   public:
     void Method2() {}
    [Obsolete("This method is obsolete; use Method2 instead.")]
     void Method1() {}
};

int main()
{
    C^ c = gcnew C();
    c->Method1();
    c->Method2();
}
