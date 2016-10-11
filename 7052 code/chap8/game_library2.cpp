// game_library.cpp
public ref class GameObject
{
   public:
      void Initialize();
      virtual void Read() { /* read data from file */ }
      virtual void Write() { /* write data to file */ }
};

void GameObject::Initialize()
{
    if (reading_from_file)
   {
        Read();  // Oops! Scroll method called.
   }

   // ...
}



public ref class Monster : GameObject
{
};

public ref class MapTile : GameObject
{
};

public ref class Item : GameObject
{
};
