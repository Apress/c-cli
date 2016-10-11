// valuetype_this.cpp

using namespace System;

value class V
{
   int i, j;

   public:

   void PrintStartingAddress()
   {
      interior_ptr<V> ptr_to_this = this;
      pin_ptr<V> pinned_this = ptr_to_this;
      Console::WriteLine("Starting address of object is 0x{0:x}",
                 reinterpret_cast<int>(pinned_this));
   }
};

int main()
{
   V v;
   v.PrintStartingAddress();
}
