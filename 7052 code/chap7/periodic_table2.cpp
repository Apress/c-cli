// periodic_table.cpp
using namespace System;
using namespace System::Collections;

value class ElementType
{
   public:
     property unsigned int AtomicNumber;
     property double AtomicWeight;
     property String^ Name;
     property String^ Symbol;

     // you cannot use initializer list syntax to initialize properties
     ElementType(String^ name, String^ symbol,
                 double a, double n)
     {
         AtomicNumber = n;
         AtomicWeight = a;
         Name = name;
         Symbol = symbol;
     }

     // override the ToString method (you'll learn more about the override
     // keyword in the next chapter)
     virtual String^ ToString() override
     {
         return String::Format(
           "Element {0} Symbol {1} Atomic Number {2} Atomic Weight {3}",
             Name, Symbol, AtomicNumber, AtomicWeight);
     }
};

ref class PeriodicTable
{
    private:

       Hashtable^ table;

    public:

       PeriodicTable()
       {
          table = gcnew Hashtable();

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
};

int main()
{
   PeriodicTable^ table = gcnew PeriodicTable();

   // get the element using the indexed property and print it
   Console::WriteLine( table["Hydrogen"] );
}
