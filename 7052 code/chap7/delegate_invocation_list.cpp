// delegate_invocation_list.cpp
using namespace System;

delegate String^ MyDelegate();

ref class R
{
   public:

   String^ f() { return "R::f"; }
   String^ g() { return "R::g"; }
   String^ h() { return "R::h"; }
};

int main()
{
   MyDelegate^ d;
   R^ r = gcnew R();

   d =  gcnew MyDelegate(r, &R::f);
   // cast the return value to this particular delegate type
   // note: the C-style cast evaluates to a safe_cast
   d = (MyDelegate^) d->Combine(d, gcnew MyDelegate(r, &R::g));
   d = (MyDelegate^) d->Combine(d, gcnew MyDelegate(r, &R::h));

   String^ s = d->Invoke();
   Console::WriteLine("Return value was {0}", s);

   d = (MyDelegate^) d->Remove(d, gcnew MyDelegate(r, &R::g));

   s = d->Invoke();
   Console::WriteLine("Return value was {0}", s);

   for each (MyDelegate^ del in d->GetInvocationList())
   {
       s = del->Invoke();
       Console::WriteLine("Return value was {0}", s);
   }

}
