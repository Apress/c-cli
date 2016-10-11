// global_function.cpp
// compile with: cl /clr:safe /LD global_function.cpp

using namespace System;

namespace G
{

   void FGlobal()
   {
      Console::WriteLine("Global C++/CLI Function.");
   }

   public ref class R
   {
      public:
        static void FMember()
        {
            Console::WriteLine("C++/CLI Static Member Function.");
            FGlobal();
        } 
   };
};
