// game_library.cpp
ref class GameObject
{
   public:
      void Initialize();
      virtual void Read() { /* read data from file */ }
      virtual void Write() { /* write data to file */ }
};


public ref class Monster : GameObject
{
};

public ref class MapTile : GameObject
{
};

public ref class Item : GameObject
{
};
