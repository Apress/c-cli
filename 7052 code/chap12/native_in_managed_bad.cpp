// native_in_managed.cpp

using namespace System;

ref class R {};

class N
{  
   R^ r;  // illegal

   public:
      N()
      {
          r = gcnew R();
      }
      
}; 
