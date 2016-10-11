// virtual_properties2.cpp

using namespace System;
using namespace System::Collections::Generic;

value class Isotope
{
   public:
     property unsigned int IsotopeNumber;
     property unsigned int AtomicNumber;
     property double Mass;
};

ref class Element
{
     double atomicWeight;

   public:
     property unsigned int AtomicNumber;
     property String^ Name;
     property String^ Symbol;

     property double AtomicWeight
     {
         virtual double get() { return atomicWeight; }
         void set(double a) { atomicWeight = a; }
     }

     Element(String^ name, String^ symbol,
                 double a, double n)
     {
         AtomicNumber = n;
         AtomicWeight = a;
         Name = name;
         Symbol = symbol;
     }
};

ref class HydrogenWithIsotopes : Element
{


   double atomicWeight;

   public:


     property List<Isotope>^ Isotopes;
     property List<double>^ IsotopeAbundance;

     property double AtomicWeight
     {
         virtual double get() override
         {
            // Check to see if atomic weight has been calculated yet.
             if (atomicWeight == 0.0)
             {
                double total = 0.0;
                if (Isotopes->Count == 0)
                    return 0.0;
                for (int i = 0; i < Isotopes->Count; i++)
                {
                    total += Isotopes[i].Mass * IsotopeAbundance[i];
                }
                atomicWeight = total /* / Isotopes->Count */ ;
             }
             return atomicWeight;
         }
     }


    public:

       HydrogenWithIsotopes() : Element("Hydrogen", "H", 0.0, 1)
       {
          Isotopes = gcnew List<Isotope>();
          IsotopeAbundance = gcnew List<double>();

          Isotope isotope1;  // Hydrogen 1
          isotope1.IsotopeNumber = 1;
          isotope1.AtomicNumber = 1;
          isotope1.Mass = 1.0078250320710; // from about.com
          Isotopes->Add(isotope1);
          IsotopeAbundance->Add(.99985);

          Isotope isotope2; // Hydrogen 2 : Deuterium
          isotope2.IsotopeNumber = 2;
          isotope2.AtomicNumber = 1;
          isotope2.Mass = 2.01410177784;
          Isotopes->Add(isotope2);
          IsotopeAbundance->Add(.000115);

          Isotope isotope3;  // Hydrogen 3 : Tritium
          isotope3.IsotopeNumber = 3;
          isotope3.AtomicNumber = 1;
          isotope3.Mass = 3.016049277725 ;
          Isotopes->Add(isotope3);
          IsotopeAbundance->Add(0); // too small

       }
};

int main()
{
   Element e("Hydrogen", "H", 1.00794, 1);
   Console::WriteLine("AtomicWeight is listed as {0}", e.AtomicWeight );
   HydrogenWithIsotopes h;
   Console::WriteLine("AtomicWeight is computed as {0}", h.AtomicWeight );
}
