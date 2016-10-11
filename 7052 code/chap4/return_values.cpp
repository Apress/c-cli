// return_values.cpp
using namespace System;

ref class R
{
     bool destroyed;
   public:
     R() { }
     R(const R% r) { }  // copy constructor

     R% GetTrackingRefMF();
     void PrintR()
     {
        if (destroyed)
           Console::WriteLine("Using destroyed object!");
        else
           Console::WriteLine("R");
     }

     ~R() { destroyed = true; }
};

value struct V
{
   int a;
   int b;
};

// Handle return value: OK
R^ GetHandle()
{
   // create a new R
   R^ r = gcnew R();
   // return it
   return r;
}

// Return reference to local variable
// -- avoid
R% GetTrackingRef()
{
   // create a new R
   R^ r = gcnew R();
   return *r; // compiler warning
}

// Return reference to local variable
// -- avoid
R% GetTrackingRef_Bad()
{
   R r;
   return r; // compiler warning
}

// OK: return a nontemporary reference
R% R::GetTrackingRefMF()
{
  return *this;
}

// Value type return value: OK
V GetValue()
{
   V v;
   v.a = 100;
   v.b = 54;
   // value gets copied
   return v;
}

// Return value with stack semantics
// Requires copy constructor
R GetR()
{
   R r;
   return r; // requires copy constructor
}


int main()
{
    // Valid uses:
    R^ r1 = GetHandle();  // OK
    R% r2 = r1->GetTrackingRefMF();  // OK
    V v1 = GetValue();  // OK
    Console::WriteLine("{0} {1}", v1.a, v1.b);

    R r3 = GetR(); // OK only if R has a copy constructor

    // Using a tracking reference in the GetTrackingRef function works
    // but a handle would work as well and would eliminate the compiler
    // warning in the function declaration
    R% r4 = GetTrackingRef();
    r4.PrintR();

    // Using the tracking reference here is not OK
    // since the destructor was called.
    R% r5 = GetTrackingRef_Bad();
    r5.PrintR();

}
