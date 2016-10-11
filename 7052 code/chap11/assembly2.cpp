// assembly2.cpp

#include "managed_template.h"

#using "assembly1.dll"

int main()
{
   CTemplate<int>^ ctemplate_int = gcnew CTemplate<int>(67);

   CBridge^ bridge = gcnew CBridge();
   bridge->F(ctemplate_int);
}
