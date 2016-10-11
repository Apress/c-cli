// interfaces_constants.cpp

interface class I
{
   static const int i = 100;     // OK : static members OK
   literal int j = 50;           // OK : literals OK
   // const int k;               // error : nonstatic field
};
