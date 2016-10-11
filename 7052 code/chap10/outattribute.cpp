// outattribute.cpp
// compile with: /clr:safe or /clr:pure

using namespace System;
using namespace System::Runtime::InteropServices;

namespace OutAttrClass
{

   public ref class C1
   {
       public:

       void Func([Out] String^% text)
       {
           text = "testing";
       }
   };
}
