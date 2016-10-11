// assembly2_with_generic.cpp

#using "generic_interface.dll"
#using "template_with_generic_interface.dll"

#include "template_with_generic_interface.h"

int main()
{
   CTemplate<int>^ ctemplate_int = gcnew CTemplate<int>(67);

   CBridge^ bridge = gcnew CBridge();
   bridge->F(ctemplate_int);
}
