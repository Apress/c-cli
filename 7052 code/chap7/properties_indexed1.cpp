// properties_indexed1.cpp
using namespace System;

ref class Numbers
{
   array<String^>^ ordinals;

   public:

      Numbers()
      {
          ordinals = gcnew array<String^> { "zero", "one", "two", "three" };
      }

      property String^ ordinal[unsigned int]
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
   Numbers^ nums = gcnew Numbers();

   // Access the property values using the indexer
   // with an unsigned int as the index.
   Console::WriteLine( nums->ordinal[0] );
}
