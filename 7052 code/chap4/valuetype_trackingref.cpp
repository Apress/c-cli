// valuetype_trackingref.cpp
using namespace System;

value struct V
{
   int a;
   int b;
};

void f(V% v)
{
   v.a = 10;
   v.b = 20;
}

int main()
{
   V v;
   v.a = 1;
   v.b = 2;
   f(v);
   Console::WriteLine("{0} {1}", v.a, v.b);
}
