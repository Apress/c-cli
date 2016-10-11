// passing_with_copy_ctor.cpp
using namespace System;

ref class R
{
   int val;
   String^ str;

   public:

    property int Value
    {
       int get() { return val; }
       void set(int i) { val = i; }
    }
    property String^ Label
    {
       String^ get() { return str; }
       void set(String^ s) { str = s; }
    }

   R(int val_in, String^ label) : val(val), str(label)
   { }

    R(const R% r)
    {
         // copy the elements of R
         // Value is a value type, so gets copied
         val = r.val;
         // strings are immutable, so
         // a reference copy will work here even
         // in a copy ctor.
         str = r.str;
    }
};
