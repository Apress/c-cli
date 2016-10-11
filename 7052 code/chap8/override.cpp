// override.cpp
using namespace System;

// the game library's classes
ref class GameObject
{
   public:
      void Initialize(bool fromFile)
      {
         if (fromFile)
         {
             Read();
         }
         else
         {
             // other code
         }
      }
      virtual void Read()
      {
         // general reading from a file for the GameObject
         Console::WriteLine("GameObject::Read");
      }
};

ref class Item : GameObject
{
    // ...
};

// the user's class
ref class Scroll : Item
{
   public:
      virtual void Read() override
      {
          // special reading from a file pertaining to scroll class
          Console::WriteLine("Scroll::Read");
      }
};

int main()
{
   Scroll^ scroll = gcnew Scroll();
   Item^ item = scroll;
   item->Initialize(true);
   scroll->Read();
}
