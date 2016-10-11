// gc_hole.cpp
using namespace System;

ref struct R
{
   array<int>^ a;

   R()
   {
      a = gcnew array<int> { 1, 2, 3, 4, 5 };
   }
};

void F(int* ptr)
{
   if (ptr)
      Console::WriteLine(*ptr);  // possible crash
}

int* GcHole(R^ r)  // gc hole
{  
   pin_ptr<int> pinp = &r->a[0];
   int *ptr;
   ptr = pinp;  // pointer assigned to pinning pointer
   // ...
   return ptr;  // pointer into gc heap returned (!)
}

int main() {
   R^ r = gcnew R;
   F(GcHole(r));
}
