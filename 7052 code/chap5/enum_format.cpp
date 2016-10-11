// enum_format.cpp
using namespace System;

enum class Color
{
    Red = 1,
    Blue = 2,
    Green = 3
};

int main()
{
   Console::WriteLine("Colors: {0}, {1}, {2}", Color::Red, Color::Blue,
       Color::Green);
   Console::WriteLine("Colors: {0:d}, {1:d}, {2:d}", Color::Red, Color::Blue,
        Color::Green);

   Color c = Color::Red;

   String^ s1 = c.ToString("X"); // specify the hex representation
   Console::WriteLine( s1 );

   // Use the Format method of the Enum class
   String^ s2 = Enum::Format( Color::typeid, c , "G");

   Console::WriteLine(s2 );
}
