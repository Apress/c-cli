// native_exception.cpp
#include <wchar.h>

using namespace System;
using namespace System::Runtime::InteropServices;

#pragma unmanaged

class NativeException
{
   wchar_t m_str[1024];

   public:

     NativeException(wchar_t* s)
     {
        wcscpy_s(m_str, s);
     }

     const wchar_t* GetMessage() { return m_str; }
};

void throw_native_exception(bool byval)
{
  if (byval)
    throw NativeException(L"Native Exception By Value");
  else
    throw new NativeException(L"Native Exception on Native Heap");
}

#pragma managed

int main()
{
   bool byval = true;

   try
   {
      throw_native_exception(byval);
   }
   catch(NativeException& native_exception)
   {
      wprintf(L"Caught NativeException: %s\n", native_exception.GetMessage());
   }
   catch(SEHException^ e)
   {
      Console::WriteLine("{0}\nErrorCode: 0x{1:x}",
            e->ToString(), e->ErrorCode);
   }

   byval = false;

   try
   {
      throw_native_exception(byval);
   }
   catch(NativeException* native_exception)
   {
      wprintf(L"Caught NativeException: %s\n", native_exception->GetMessage());
   }
   catch(SEHException^ e)
   {
      Console::WriteLine("{0}\nErrorCode: 0x{1:x}",
            e->ToString(), e->ErrorCode);
   }
}



