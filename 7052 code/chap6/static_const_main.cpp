// static_const_main.cpp

#using "static_const_vs_literal.dll"

template<int i>
void f()
{ }

int main()
{
   int a1[R::i]; // error: static const R::i isn't considered a constant
   int a2[R::j]; // OK

   f<R::i>();  // error
   f<R::j>();  // OK
}
