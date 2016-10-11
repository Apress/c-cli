// property_static.cpp
value class ElementType
{
   public:

      // Periodic Table of the Elements
      static property array<ElementType>^ PeriodicTable;

      static ElementType()
      {
          PeriodicTable = gcnew array<ElementType>(120);
         // initialize each element and its properties
      }
};
