// template_with_generic_interface.cpp

#include "template_with_generic_interface.h"

using namespace System;

public ref class CBridge
{
   public:

   static void F(IGInterface<int>^ ct_int)
   {
      Console::WriteLine("{0} ", ct_int->InnerObject );
   }
};
