// interface_constraint.cpp

interface class I
{
    void f();
};

// The constraint is introduced with the where keyword
// and requires that T inherit from I.
generic <typename T> where T : I
ref class R
{
    T t;

    public:
       R(T t_in) : t(t_in)
       {
           // Call the method on I.
           // This code would not compile without
           // the constraint.
           t->f();
       }
};

ref class C : I
{
   public:
       virtual void f()
       {
           // ...
       }
};

int main()
{
     R<C^>^ r = gcnew R<C^>(gcnew C());
}
