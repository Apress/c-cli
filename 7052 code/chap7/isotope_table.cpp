// isotope_table.cpp
using namespace System;
using namespace System::Collections::Generic;

value class Isotope
{
   public:
     property unsigned int IsotopeNumber;
     property unsigned int AtomicNumber;
};

value class ElementType
{
   public:
     property unsigned int AtomicNumber;
     property double AtomicWeight;
     property String^ Name;
     property String^ Symbol;

     ElementType(String^ name, String^ symbol,
                 double a, double n)
     {
         AtomicNumber = n;
         AtomicWeight = a;
         Name = name;
         Symbol = symbol;
     }

     virtual String^ ToString() override
     {
         return String::Format(
            "Element {0} Symbol {1} Atomic Number {2} Atomic Weight {3}",
             Name, Symbol, AtomicNumber, AtomicWeight);
     }

     property List<Isotope>^ Isotopes;

};

ref class PeriodicTable
{
    private:

       static System::Collections::Hashtable^ table;    

    public:

       static PeriodicTable()
       {
          table = gcnew System::Collections::Hashtable();

          ElementType element("Hydrogen", "H", 1.0079, 1);

          // Add to the Hashtable using the key and value
          table->Add(element.Name, element);

          // add the other elements...
       }

       property ElementType default[String^]
       {
           ElementType get(String^ key)
           {
               return safe_cast<ElementType>( table[key] );
           }
       }

    static property System::Collections::Hashtable^ Elements
    {
        System::Collections::Hashtable^ get() { return table; }
    }

   };




ref class IsotopeTable
{
    private:

       Dictionary<String^, Isotope>^ isotopeTable;

    public:

       IsotopeTable()
       {
          isotopeTable = gcnew Dictionary<String^, Isotope>();

          // add the elements and their isotopes...
          // additional code for the elements is assumed
          for each (ElementType element in PeriodicTable::Elements)
          {

             // Add each isotope to the isotopes table.
             for each (Isotope isotope in element.Isotopes)
             {
                isotopeTable->Add(element.Name + isotope.IsotopeNumber, isotope);
             }
          }
       }

       // Pass in the element symbol and isotope number, e.g "C" and 14 for
       // carbon-14
       property Isotope ElementIsotope[String^, int ]
       {
           Isotope get(String^ key, int isotopeNumber)
           {
               key = key + isotopeNumber.ToString();
               return isotopeTable[key];
           }
       }
};
