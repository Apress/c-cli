// property_accessor_delegate.cpp
using namespace System;

delegate double ValueAccessor();

value class ElementType
{
   public:
     property double AtomicWeight;
};

int main()
{
  ElementType oxygen;
  oxygen.AtomicWeight = 15.9994;
  ValueAccessor^ get_method = gcnew ValueAccessor(oxygen,
          &ElementType::AtomicWeight::get);

  Console::WriteLine("{0}", get_method->Invoke());
}
