// atom_interfaces.cpp

#include "atom_with_enum.cpp"

interface class IRadioactive
{
   void AlphaDecay();
   void BetaDecay();
   double GetHalfLife();
};

ref class RadioactiveAtom : Atom, IRadioactive
{
       double half_life;

       void UpdateHalfLife()
       {
           // ...
       }


    public:
       // the atom releases an alpha particle
       // so it loses two protons and two neutrons
       virtual void AlphaDecay()
       {
           SetAtomicNumber(GetAtomicNumber() - 2);
           SetIsotopeNumber(GetIsotopeNumber() - 4);
           UpdateHalfLife();
       }

       // the atom releases an electron
       // a neutron changes into a proton
       virtual void BetaDecay()
       {
           SetAtomicNumber(GetAtomicNumber() + 1);
           UpdateHalfLife();
       }

       virtual double GetHalfLife()
       {
           return half_life;
       }
};
