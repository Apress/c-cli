// generic_class1.cpp
using namespace System;

generic <typename T>
ref class R
{
   T t;

   public:

      R() {}

      property T InnerValue
      {
          T get() { return t; }
          void set(T value) { t = value; }
      }
};

int main()
{
   double d = 0.01;
   int n = 12;

   // Create an object with T equal to double.
   R<double>^ r_double = gcnew R<double>();

   // Create an object with T equal to int.
   R<int>^ r_int = gcnew R<int>();

   r_double->InnerValue = d;

   r_int->InnerValue = n;

   Console::WriteLine( r_double->InnerValue );

   Console::WriteLine( r_int->InnerValue );
}
