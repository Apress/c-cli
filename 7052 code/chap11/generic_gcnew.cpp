// generic_gcnew.cpp
using namespace System;

generic <typename T> where T: gcnew()
T CreateInstance()
{
   return gcnew T();
}

ref class R
{
   public:

   R() { }
};

int main()
{
   int i = CreateInstance<int>();
   R^ r = CreateInstance<R^>();
}
