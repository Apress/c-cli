// pass_by_value.cpp
using namespace System;

ref struct R
{
   R()
   {
      val = 1;
   }

   // copy constructor
   R( R% r)
   {
      val = r.val;
   }

   property int val;
};

// R passed by value (no ^)
void f(R r_local)
{
   // modify r without affecting outer scope
   r_local.val = 2;
   Console::WriteLine("Within f: " + r_local.val);
}

int main()
{
    R r;
    f(r);
    Console::WriteLine("Outside f: " + r.val);

    // The same code, using heap semantics
    R^ rhat = gcnew R();
    f(*rhat);  // dereference the handle
    Console::WriteLine("Outside f: " + rhat->val);
}
