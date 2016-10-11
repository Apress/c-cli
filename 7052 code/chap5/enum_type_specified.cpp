// enum_type_specified.cpp
using namespace System;

enum class Ordinal : char
{
   zero, one, two, three, four, five, six, seven, eight, nine, ten,
   eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen,
   eighteen, nineteen, twenty
};

int main()
{
   char c1 = 13;
   char c2 = 156;
   Ordinal ord1 = safe_cast<Ordinal>(c1);
   Console::WriteLine(ord1.ToString());
}
