// throw_string.cpp

using namespace System;

public ref class R
{
public:
   static void TrySomething()
   {
      throw gcnew String("Error that throws string!");
   }
};

int main()
{
   try
   {
      R::TrySomething();
   }
   catch(String^ s)
   {
      Console::WriteLine(s);
   }
}
