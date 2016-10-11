
enum class Element
{
   Hydrogen = 1, Helium, Lithium, Beryllium, Boron, Carbon, Nitrogen, Oxygen,
   Fluorine, Neon
   // ... 100 or so other elements omitted for brevity
};

ref class Atom
{
   private:
      array<double>^ pos;

   public:

       Atom(double x, double y, double z, unsigned int a, unsigned int n)
       {
          pos = gcnew array<double>(3);
          pos[0] = x; pos[1] = y; pos[2] = z;

          AtomicNumber = a;
          IsotopeNumber = n;
       }

       property unsigned int AtomicNumber;
       property unsigned int IsotopeNumber;

       property Element ElementType
       {
          Element get()
          {
              return safe_cast<Element>(AtomicNumber);
          }
          void set(Element element)
          {
              AtomicNumber = safe_cast<int>(element);
          }
       }

      property double Position[int]
       {
          // if index is out of range, the array access will
          // throw an IndexOutOfRange exception
          double get(int index)            {
             return pos[index];
          }
          void set(int index, double value)
          {
             pos[index] = value;
          }
       }

  virtual void AlphaDecay()
  {
      AtomicNumber -= 2;
      IsotopeNumber -= 4;
      UpdateHalfLife();
  }

  void UpdateHalfLife() { /* TODO */ }

};
