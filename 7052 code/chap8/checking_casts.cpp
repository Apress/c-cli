// checking_casts.cpp

using namespace System;

ref class Base {};
ref class Derived : Base {} ;


int main()
{

Base^ b = gcnew Base();
Derived^ d = gcnew Derived();
// using safe_cast
try
{
   d = safe_cast<Derived^>(b);
}
catch (InvalidCastException^ e)
{
    // handle error
}

// using dynamic cast
d = dynamic_cast<Derived^>(b);
if (d == nullptr)
{
    // handle error
}
 
}