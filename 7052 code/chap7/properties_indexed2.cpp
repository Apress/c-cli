// properties_indexed2.cpp
using namespace System;

ref class Numbers
{
   array<String^>^ ordinals;

   public:

      Numbers()
      {
          ordinals = gcnew array<String^> { "zero", "one", "two", "three" };
      }

      property String^ default[unsigned int]
      {
         String^ get(unsigned int index)
         {
             return ordinals[index];
         }
         void set(unsigned int index, String^ value)
         {
             ordinals[index] = value;
         }
      }
};

int main()
{
   Numbers nums;

   // Access property using array indexing operators on the
   // instance directly.
   Console::WriteLine( nums[0] );

   // If using a handle, you can still use array syntax.
   Numbers^ nums2 = gcnew Numbers();
   Console::WriteLine( nums2[1] );

   // You can also use the name "default" and access like a
   // named property.

   Console::WriteLine( nums.default[2] );
   Console::WriteLine( nums2->default[3] );
}
