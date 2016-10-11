// enum_flags.cpp
using namespace System;

[ Flags ]
enum class FontFormat
{
    None = 0,  // No flags set.
    BOLD = 1,  // the values are set to powers of 2
    ITALIC = 2,  // so that in binary, each represents one bit position
    UNDERLINE = 4,
    STRIKETHROUGH = 8,
    RED = 16,
    FLASHING = 32,
    BOLD_ITALIC = BOLD | ITALIC  // combination of two values
};

ref class Font
{
   public:

      property String^ Name;

      Font(String^ s) { Name = s; }
};

ref class Display
{
   public:

   static void SetFont(Font^ font, FontFormat format)
   {
        // Testing the bits of a Flags enum using the bitwise and operator (&)
        // requires a cast to int.
        if (safe_cast<int>(format) & safe_cast<int>(FontFormat::BOLD))
        {
            // use a bold font
        }
        if (safe_cast<int>(format) & safe_cast<int>(FontFormat::ITALIC))
        {
            // use italics
        }
        // etc.
   };

};

int main()
{
   // The bitwise or operator (|) combines the flag values
   Display::SetFont(gcnew Font("Times New Roman"),
        FontFormat::BOLD | FontFormat::RED );

   Display::SetFont(gcnew Font("Helvetica"),
        FontFormat::ITALIC | FontFormat::FLASHING );
}
