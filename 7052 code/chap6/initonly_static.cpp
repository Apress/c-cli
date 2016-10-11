// initonly_static_cpp
using namespace System;

ref class R
{
   public:

   static initonly String^ name = "Ralph";  // OK
   // initonly String^ name = "Bob"; // error!

   // rest of class declaration
};
