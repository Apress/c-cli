// radioactive_decay.cpp
using namespace System;

// This declares a delegate type that takes no parameters
delegate void DecayProcessFunc();

enum class Element
{
   Hydrogen = 1, Helium, Lithium, Beryllium, Boron, Carbon, Nitrogen, Oxygen,
   Fluorine, Neon
   // ... 100 or so other elements omitted for brevity
};

ref class Atom
{
 
   

   public:

       Atom( unsigned int a, unsigned int n)
       {
   
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




};

ref class RadioactiveAtom : Atom
{

    public:
       RadioactiveAtom(int a, int n, bool is_stable, double half_life)
           : Atom(a, n)
       {
            IsStable = is_stable;
            HalfLife = half_life;
            Lambda = Math::Log(2) / half_life;
        }

       // the atom releases an alpha particle
       // so it loses two protons and two neutrons
       virtual void AlphaDecay()
       {
           AtomicNumber -= 2;
           IsotopeNumber -= 4;
           Update();
       }

       // the atom releases an electron
       void BetaDecay()
       {
           AtomicNumber++;
           Update();
       }

       property bool IsStable;
       property double HalfLife;
       property double Lambda;
       void Update()
       {
          // In this case we assume it decays to a stable nucleus.
          // nullptr is the C++/CLI way to refer to an unassigned handle.
          DecayProcess = nullptr;
          IsStable = true;
       }

       // Declare the delegate property. We'll call this when
       // an atom decays.
       property DecayProcessFunc^ DecayProcess;

}; // ref class RadioactiveAtom

void SimulateDecay(int a, int n, double halflife, int step,
                   int max_time, int num_atoms, int seed)
{
   array<RadioactiveAtom^>^ atoms = gcnew array<RadioactiveAtom^>(num_atoms);

   // Initialize the array.
   // We cannot use a for each statement here because the for each
   // statement is not allowed to modify the atoms array.
   for (int i = 0; i < num_atoms; i++)
   {
      atoms[i] = gcnew RadioactiveAtom(a, n, false, halflife);
      // create the delegate
      atoms[i]->DecayProcess =
          gcnew DecayProcessFunc(atoms[i], &RadioactiveAtom::BetaDecay);
   }

   Random^ rand = gcnew Random(seed);
   for (int t = 0; t < max_time; t++)
   {
       for each (RadioactiveAtom^ atom in atoms)
       {
            if ((!atom->IsStable) && atom->Lambda * step > rand->NextDouble())
            {
                // invoke the delegate
                atom->DecayProcess->Invoke();
            }
       }
   }
}

int main()
{
   // Carbon-14.  Atomic Number: 6  Isotope Number 14
   // Half-Life 5730 years
   // Number of atoms 10000
   // Maximum time 10000
   // Random number seed 7757
   SimulateDecay(6, 14, 5730, 1, 10000, 10000, 7757);
}
