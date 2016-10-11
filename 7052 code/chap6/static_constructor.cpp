// static_constructor.cpp
using namespace System;

ref class C
{
  private:
    static String^ data;

  static C()
  {
      Console::WriteLine("C static constructor called.");
      data = "Initialized";
  }

public:

  C()
  {
      Console::WriteLine("C Constructor called.");
      Console::WriteLine(data);
  }

};

int main()
{
   Console::WriteLine("main method");
   C c1;
   C^ c2 = gcnew C();
}
