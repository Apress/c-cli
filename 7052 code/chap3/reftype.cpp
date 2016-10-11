// reftype.cpp
using namespace System;

ref class RefType
{
   String^ classname;

   public:

   RefType()
   {
      classname = gcnew String("RefType");
   }

   String^ GetMessage()
   {
       return String::Format("I am a " + classname);
   }

};

int main()
{
   RefType^ r = gcnew RefType();
   Console::WriteLine(r->GetMessage());
}
