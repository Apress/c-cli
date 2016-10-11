// generic_reference_syntax.cpp

interface class I { void F(); };

value struct V : I { virtual void F() {} };

ref struct R : I { virtual void F() {} };

generic <typename T> where T : I
ref class G
{
   T t;

   public:
      G(T t)
      {
          // The handle syntax -> is used
          // even though T could be a value type.
          t->F();
      }
};

int main()
{
   V v;
   R^ r = gcnew R();
   G<V>^ gv = gcnew G<V>(v);
   G<R^>^ gr = gcnew G<R^>(r);
}
