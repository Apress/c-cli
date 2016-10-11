// native_message_box.cpp
#include "native_message_box_class.h"

int main()
{
   MessageBoxClass* messageBox = new MessageBoxClass(
        L"Do you like this example?", L"Native message box", 
        static_cast<MessageBoxType>(YESNOCANCEL | ICONASTERISK));

   int result = messageBox->Display();

   wchar_t wstr[1024];
   swprintf_s( wstr, L"The dialog result was %d", result);
   messageBox->SetMessage(wstr);
   messageBox->SetType(OK);
   messageBox->Display();

}
