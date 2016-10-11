// arrays_nondefault_ctor.cpp
using namespace System;

ref class C
{

   public:
      C(int i) { Value = i; }

      property int Value;
};

int main()
{
   array<C^>^ array_C = { gcnew C(0), gcnew C(1), gcnew C(2)};

   Console::WriteLine( " {0}, {1}, {2} ", array_C[0]->Value,
                  array_C[1]->Value, array_C[2]->Value);
}
