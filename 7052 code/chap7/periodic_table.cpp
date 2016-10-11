// periodic_table.cpp
using namespace System;
using namespace System::Collections::Generic;

value class Isotope
{
   public:
     property double Mass;
     property unsigned int AtomicNumber;
};

value class ElementType
{
   List<Isotope>^ isotopes;
   List<double>^ isotope_abundance;
   double atomicWeight;

   public:
     property unsigned int AtomicNumber;
     property String^ Name;
     property String^ Symbol;

     property double AtomicWeight
     {
         double get()
         {
             // check to see if atomic weight has been calculated yet
             if (atomicWeight == 0.0)
             {
                if (isotopes->Count == 0)
                    return 0.0;
                for (int i = 0; i < isotopes->Count; i++)
                {
                    atomicWeight += isotopes[i].Mass * isotope_abundance[i];
                }
             }
             return atomicWeight;
         }
         void set(double value)
         {
             // used if you look up atomic weight instead of calculating it
             atomicWeight = value;
         }
     }

     // other properties same as before
};
