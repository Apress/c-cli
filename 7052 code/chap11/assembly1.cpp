// assembly1.cpp

#include "managed_template.h"

using namespace System;

public ref class CBridge
{
   public:

   static void F(CTemplate<int>^ ct_int)
   {
      Console::WriteLine("{0} ", ct_int->InnerObject );
   }
};

int main()
{
   CTemplate<int>^ ct_int;
   ct_int = gcnew CTemplate<int>(55);
   CBridge::F(ct_int);
}
