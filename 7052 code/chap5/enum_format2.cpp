// enum_format2.cpp
using namespace System;

// Use the FlagsAttribute
[ Flags ]
enum class Color
{
    Red = 1,
    Blue = 2,
    Green = 4   // use powers of 2
};

int main()
{
   Console::WriteLine("Colors: {0}, {1}, {2}", Color::Red, Color::Blue,
       Color::Green);
   Console::WriteLine("Colors: {0:d}, {1:d}, {2:d}", Color::Red, Color::Blue,
    Color::Green);

   // Use the bitwise OR operator to combine flags.
   Color c = Color::Red | Color::Blue;

   String^ s1 = c.ToString("X"); // specify the hex representation
   Console::WriteLine( s1 );

   // Use the Format method of the Enum class
   String^ s2 = Enum::Format( Color::typeid, c , "G");

   Console::WriteLine(s2 );
}
