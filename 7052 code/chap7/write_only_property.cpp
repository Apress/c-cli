ref class Atom
{
    unsigned int atomic_number;

    public:
       property unsigned int IsotopeNumber;
       property unsigned int AtomicNumber
       {
            // anyone can get the atomic number
            public: unsigned int get()
            {
                return atomic_number;
            }
            // only derived classes (such as RadioactiveAtom)
            // can change the atomic number
            protected: void set(unsigned int n)
            {
                atomic_number = n;
            }
       }
};

ref class RadioactiveAtom : Atom
{
    // other stuff

    public:

      void AlphaDecay()
      {
          AtomicNumber -= 2;
          IsotopeNumber -= 4;
      }
};
