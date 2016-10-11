// native_message_box_class.h

#include <wchar.h>
#include <windows.h>

enum MessageBoxType
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

class MessageBoxClass
{
 
   wchar_t* m_message;
   wchar_t* m_caption;
   MessageBoxType m_type;
   static const size_t sz = 1024;

   public:

   MessageBoxClass(const wchar_t* message, const wchar_t* caption,
                   MessageBoxType type)
      :  m_type(type)
   {
      m_message = new wchar_t[sz];
      m_caption = new wchar_t[sz];
      wcscpy_s(m_message, sz, message); // using the "safe" CRT
      wcscpy_s(m_caption, sz, caption);
   }

   void SetMessage(const wchar_t* message)
   {
      if (message != NULL)
      {
        wcscpy_s(m_message, sz, message);
      }
   }
   const wchar_t* GetMessage() const { return m_message; }

   void SetCaption(const wchar_t* caption)
   {
      if (caption != NULL)
      {
         wcscpy_s(m_caption, sz, caption);
      }
   }
   const wchar_t* GetCaption() const { return m_caption; }

   MessageBoxType GetType() const { return m_type; }
   void SetType(MessageBoxType type){ m_type = type; }

   

   int Display()
   {
      return MessageBoxW(0, m_message, m_caption, m_type);
   }

   ~MessageBoxClass()
   {
      delete m_message;
      delete m_caption;
   }
      
};
