// managed_templates.cpp

#include "managed_template.h"

using namespace System;

int main()
{
   CTemplate<int>^ ct_int;
   CTemplate<String^>^ ct_string;

   ct_int = gcnew CTemplate<int>(55);
   ct_string = gcnew CTemplate<String^>("test");

   Console::WriteLine("{0} ", ct_int->InnerObject );
   Console::WriteLine("{0} ", ct_string->InnerObject );

}
