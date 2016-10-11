// atom.cpp
class Atom
{
   private:
      double pos[3];
      unsigned int atomicNumber;
      unsigned int isotopeNumber;

   public:
       Atom() : atomicNumber(1), isotopeNumber(1)
       {
           // Let's say we most often use hydrogen atoms,
           // so there is a default constructor that assumes you are
           // creating a hydrogen atom.
           pos[0] = 0; pos[1] = 0; pos[2] = 0;
       }

       Atom(double x, double y, double z, unsigned int a, unsigned int n)
        : atomicNumber(a), isotopeNumber(n)
       {
          pos[0] = x; pos[1] = y; pos[2] = z;
       }
       unsigned int GetAtomicNumber() { return atomicNumber; }
       void SetAtomicNumber(unsigned int a) { atomicNumber = a; }
       unsigned int GetIsotopeNumber() { return isotopeNumber; }
       void SetIsotopeNumber(unsigned int n) { isotopeNumber = n; }
       double GetPosition(int index) { return pos[index]; }
       void SetPosition(int index, double value) { pos[index] = value; }
};
