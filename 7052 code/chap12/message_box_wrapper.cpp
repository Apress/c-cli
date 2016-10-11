// message_box_wrapper.cpp

#include "native_message_box_class.h"
#include <vcclr.h>

using namespace System;

enum class MessageBoxTypeEnum
{
  OK, OKCANCEL, ABORTRETRYIGNORE,
  YESNOCANCEL, YESNO,
  RETRYCANCEL, CANCELTRYCONTINUE,
  ICONHAND = 0x10,
  ICONQUESTION = 0x20,
  ICONEXCLAMATION = 0x30,
  ICONASTERISK = 0x40,
  TYPEMASK = 0xF,
  ICONMASK = 0xF0
};

wchar_t* MarshalString(String^ s, size_t sizeInCharacters)
{
   pin_ptr<const wchar_t> pinnedChars = PtrToStringChars(s);
   wchar_t* wcs = new wchar_t[sizeInCharacters];
   wcscpy_s(wcs, sizeInCharacters, pinnedChars);
   return wcs;
}

public ref class MessageBoxWrapper
{

   MessageBoxClass* nativeMessageBox;
   literal unsigned int maxSize = 1024;

   public:

   MessageBoxWrapper(String^ message, String^ caption, MessageBoxTypeEnum type)
   {
     pin_ptr<const wchar_t> pinnedMessage = PtrToStringChars(message);
     pin_ptr<const wchar_t> pinnedCaption = PtrToStringChars(caption);

     nativeMessageBox = new MessageBoxClass(
        pinnedMessage, pinnedCaption,
        static_cast<MessageBoxType>(type));
   }

   property String^ Caption
   {
       String^ get()
       {
           return gcnew String(nativeMessageBox->GetCaption());
       }
       void set(String^ s)
       {
           nativeMessageBox->SetCaption( MarshalString(s, maxSize) );
       }
   }
   property String^ Message
   {
       String^ get()
       {
           return gcnew String(nativeMessageBox->GetCaption());
       }
       void set(String^ s)
       {
           nativeMessageBox->SetMessage( MarshalString(s, maxSize) );
       }
   }
   property MessageBoxTypeEnum Type
   {
       MessageBoxTypeEnum get()
       {
           return static_cast<MessageBoxTypeEnum>(nativeMessageBox->GetType());
       }
       void set(MessageBoxTypeEnum t)
       {
           nativeMessageBox->SetType( static_cast<MessageBoxType>( t ));
       }
   }
   int Display()
   {
      if (nativeMessageBox != NULL)
        return nativeMessageBox->Display();
      else return -1;
   }

   ~MessageBoxWrapper()
   {
      this->!MessageBoxWrapper();
   }

   !MessageBoxWrapper()
   {
       delete nativeMessageBox;

   }

};

int main()
{
   MessageBoxWrapper^ wrapper = gcnew MessageBoxWrapper(
      "Do you like this message box?",
      "Managed wrapper message box.",
       MessageBoxTypeEnum::YESNO);
   Console::WriteLine("Message is: {0}", wrapper->Message);
   int result = wrapper->Display();
   Console::WriteLine("Result was {0}", result);
}
