// initonly.cpp
using namespace System;

ref class R
{
   initonly String^ name;

   public:

   R(String^ first, String^ last)
   {
       name = first + last;
   }

   void Print()
   {
       name = "Bob Jones";        // error!
       Console::WriteLine(name);  // OK
   }
};

int main()
{
   R^ r = gcnew R("Mary", "Colburn");
   r->Print();
}
