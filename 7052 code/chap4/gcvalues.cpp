// gc_lvalues.cpp

value struct V
{
   int i;
};

ref class R
{
   public:

  V m_v;

};

R^ GetRHandle() { return gcnew R(); }

int main()
{
    // i is an lvalue, 12 is an rvalue
    int i = 12;

    // an lvalue i2; i is used here as an rvalue
    // lvalues can always be used as rvalues
    int i2 = i;
    V v; // value type on the stack
    R r; // reference type (on the managed heap but with stack semantics)

    int& i3 = i;  // native reference: an lvalue
    int% i4 = i;  // tracking reference: lvalues can be assigned gc-rvalues
    int& i5 = v.i; // OK: v.i is a stack-based object
    int& i6 = r.m_v.i; // Illegal: r is a managed heap-based object
    i4 = v.i;  // OK: i4 is a gc-lvalue

    R^ r1, ^r2;    // r1 and r2 are gc-lvalues
    // gcnew R() is a gc-rvalue
    r1 = gcnew R();
    // GetRHandle() is a gc-rvalue, too
    r2 = GetRHandle();

    R% r3 = *r1; // a gc-lvalue r3 is assigned to the gc-rvalue *r1
}
