// atom_with_enum.cpp

using namespace System;

value struct Point3D
{
   double x;
   double y;
   double z;

};

enum class Element
{
   Hydrogen = 1, Helium, Lithium, Beryllium, Boron, Carbon, Nitrogen, Oxygen,
   Fluorine, Neon
   // ... 100 or so other elements omitted for brevity
};


ref class Atom
{
   private:
      Point3D position;
      unsigned int atomicNumber;
      unsigned int isotopeNumber;

   public:
       Atom(Point3D pos, unsigned int a, unsigned int n)
        : position(pos), atomicNumber(a), isotopeNumber(n)
       { }

       // ...

       Element GetElementType()
       {
           return safe_cast<Element>( atomicNumber );
       }
       void SetElementType(Element element)
       {
           atomicNumber = safe_cast<unsigned int>(element);
       }
       String^ GetElementString()
       {
          return GetElementType().ToString();
       }



       // the rest of the code is unchanged

};
