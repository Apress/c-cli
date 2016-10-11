// delegate_with_exceptions.cpp
using namespace System;

delegate String^ MyDelegate();

ref class R
{
   public:

   String^ f() {  throw gcnew Exception(); return "R::f"; }
   String^ g() { return "R::g"; }
   String^ h() { return "R::h"; }
};

int main()
{
   MyDelegate^ d;
   R^ r = gcnew R();

   d = gcnew MyDelegate(r, &R::f);
   d = safe_cast<MyDelegate^>(d->Combine(d, gcnew MyDelegate(r, &R::g)));
   d = safe_cast<MyDelegate^>(d->Combine(d, gcnew MyDelegate(r, &R::h)));

   for each (MyDelegate^ del in d->GetInvocationList())
   {
       try
       {
          String^ s = del->Invoke();
          Console::WriteLine("Return value was {0}", s);
       }
       catch(Exception^)
       {
           // handle the exception
       }
   }

}
