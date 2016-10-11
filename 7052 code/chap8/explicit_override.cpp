// explicit_override.cpp
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
      virtual void GameObjectRead() = GameObject::Read
      {
          // Read a file with additional parsing.
          Console::WriteLine("Scroll::GameObjectRead");
      }
      virtual void Read() new
      {
          // Read the scroll.
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
