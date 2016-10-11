// interop_messagebox.cpp

#include <windows.h>
#include <vcclr.h> // for PtrToStringChars

using namespace System;

public ref class MessageBoxClass
{
   public:

   property String^ Message;
   property String^ Caption;

   int DisplayBox()
   {
      // Use pinning pointers to lock down the data while it's being
      // used in native code.
      pin_ptr<const wchar_t> message = PtrToStringChars(Message);
      pin_ptr<const wchar_t> caption = PtrToStringChars(Caption);
      return MessageBoxW( 0, message,  caption, MB_OK);
   }
};

int main()
{
   MessageBoxClass m;
   m.Message = "Managed string used in native function";
   m.Caption = "Managed Code using Win32 Message Box";
   m.DisplayBox();
}
