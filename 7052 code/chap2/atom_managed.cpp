// atom_managed.cpp
ref class Atom
{
   private:
      array<double>^ pos;  // declare the managed array
      unsigned int atomicNumber;
      unsigned int isotopeNumber;

   public:
       Atom()
       {
           // We'll need to allocate space for the position values.
           pos = gcnew array<double>(3);
           pos[0] = 0; pos[1] = 0; pos[2] = 0;
           atomicNumber = 1;
           isotopeNumber = 1;
       }
       Atom(double x, double y, double z, unsigned int atNo, unsigned int n)
        : atomicNumber(atNo), isotopeNumber(n)
       {
          // create the managed array
          pos = gcnew array<double>(3);
          pos[0] = x; pos[1] = y; pos[2] = z;
       }
       // the rest of the class declaration is unchanged
};


