// abstract_classes.cpp

// Notice that the abstract keyword follows the class name.
ref class GameObject abstract
{
   int ID;

   public:

      // an abstract method with no implementation
      // provided
      virtual void ReadFromFile() abstract;

      // a nonabstract virtual method with an implementation
      virtual void UpdateID(int id)
      {
          ID = id;
      }
};

ref class Monster : GameObject
{

    public:
      // overrides the base class abstract function
      virtual void ReadFromFile() override
      {
          // code to read in data for the type
      }
};
