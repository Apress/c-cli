// native_in_managed2.cpp

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace System;
using namespace System::Runtime::InteropServices;

// template for embedding a native class
// in a reference type
template<typename T>
ref class native_root
{
  T* t;
 
  !native_root()
  {
     if (t)
     {
        delete t;
        t = NULL;
     }
  }
 
  ~native_root()
  {
     this->!native_root();
  }

  public:

     native_root() : t(new T) {}
 
     // these must be static to prevent them from being used
     // within the class (e.g. when we use this-> in ~native_root)

     // allows access to the underlying pointer
     static T* operator&(native_root% n) { return n.t; }
     // allows -> to be used to access members
     static T* operator->(native_root% n) { return n.t; }
};

class native_exception {};

// typical native class
class NativeClass
{
   FILE* fp;
   static const int TIME_BUFFER_SIZE = 32;
 
   public:
      NativeClass()
      {
         printf("Opening the file.\n");
         // open a file for Unicode writing.
         int errcode = fopen_s(&fp, "myfile.txt", "a+, ccs=UNICODE");
         if (errcode != 0)
         {
            throw new native_exception;
         }
      }
 
      void OutputText(const wchar_t* text)
      {
          if (fp)
          {
             wprintf(text);
             fwprintf(fp, text);
          }
          else
          {
              throw new native_exception;
          }  
      }

      void TimeStamp()
      {
          tm newtime;
          __time32_t time;
          wchar_t time_text[TIME_BUFFER_SIZE];
          _time32( &time );
          _localtime32_s( &newtime, &time );
          _wasctime_s(time_text, TIME_BUFFER_SIZE, &newtime);
          if (fp)
          {
             wprintf(time_text);
             fwprintf(fp, time_text);
          }
          else
          {
              throw new native_exception;
          }
      }

      ~NativeClass()
      {
         printf("Closing the file.\n");
         if (fp)
         {
            fclose(fp);
         }
      }         
};

// A reference type enclosing a Native Class
ref class R
{
   native_root<NativeClass> n;

   public:

      R() { }

      // marshal the String to a Unicode string
      // and pass the pointer to the native class method
      void OutputToFile(String^ s)
      { 
        IntPtr ptr = Marshal::StringToHGlobalUni(s);
        n->OutputText(static_cast<wchar_t*>( ptr.ToPointer()));
        n->TimeStamp();
        Marshal::FreeHGlobal(ptr);
      }
};

int main()
{
  R^ r1 = gcnew R();
  r1->OutputToFile("Output through native class!\n");
  delete r1; // the file is closed 

  R r2;
  r2.OutputToFile("More output\n");
  // file is closed again when r2 is cleaned up
}

