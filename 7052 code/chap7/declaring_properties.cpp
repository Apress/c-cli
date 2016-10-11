using namespace System;

value class ElementType
{
   public:
     property unsigned int AtomicNumber;
     property double AtomicWeight;
     property String^ Name;
     property String^ Symbol;
};

int main()
{
   ElementType oxygen;
   oxygen.AtomicNumber = 8;
   oxygen.AtomicWeight = 15.9994;
   oxygen.Name = "Oxygen";
   oxygen.Symbol = "O";

   Console::WriteLine("Element: {0} Symbol: {1}", oxygen.Name, oxygen.Symbol);
   Console::WriteLine("Atomic Number: {0} Atomic Weight: {1}",
                      oxygen.AtomicNumber, oxygen.AtomicWeight);
}
