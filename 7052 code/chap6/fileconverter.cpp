// file_converter.cpp
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vcclr.h> // for PtrToStringChars

using namespace System;
using namespace System::IO;

// a native class

class FileNative
{
   // a CRT file pointer
   FILE* fp;

   public:

   void Open(const char* filename)
   {
      int err = fopen_s(&fp, filename, "r");
      if (err)
      {
         printf("Error opening file %s. Error code %d.\n", filename, err);
      }
   }

   int Read(char* line)
   {
      int val = fread(line, 1, 1, fp);
      if (feof(fp))
      {
         return 0;
      }
      return val;
   }

   void Close()
   {
      if (fp)
        fclose(fp);
   }
};

// a managed class that contains a managed resource (StreamWriter)
// and a native resource (fileNative, a native class containing a native file).
ref class FileConverter
{
   FileNative* fileNative;
   StreamWriter^ sw;

   public:

   FileConverter(String^ source_file)
   {
       fileNative = new FileNative();
       pin_ptr<const wchar_t> wfilename = PtrToStringChars(source_file);
       size_t convertedChars = 0;
       size_t  sizeInBytes = ((source_file->Length + 1) * 2);
       errno_t err = 0;
       char    *filename = (char *)malloc(sizeInBytes);

       err = wcstombs_s(&convertedChars,
                    filename, sizeInBytes,
                    wfilename, sizeInBytes);
       if (err != 0)
       printf_s("wcstombs_s  failed!\n");

       fileNative->Open(filename);
   }

   void Convert(String^ dest_file)
   {
      String^ text;
      char ptr[1024];
      int len;
      try
      {
         sw = gcnew StreamWriter(dest_file);
      }
      catch(Exception^ e)
      {
         Console::WriteLine("Error occurred. {0}", e->Message);
      }
      while ((len = fileNative->Read(ptr)) != 0)
      {
          // This version of the string constructor takes
          // a char* pointer, an offset, and a number of characters
          // to create the String from a portion of a character array.
          text = gcnew String(ptr, 0, len);
          Console::Write(text);
          sw->Write(text);
      }
   }

   // A way to close the files promptly without waiting
   // for the cleanup to occur.
   void Close()
   {
     if (sw != nullptr)
        sw->Close();
     fileNative->Close();
   }

   // Destructor: close the managed filestream, and call finalizer.
   ~FileConverter()
   {
      if (sw != nullptr)
         sw->Close();
      this->!FileConverter();
   }

   // Finalizer: close the native file handle.
   !FileConverter()
   {
      fileNative->Close();
   }

};


int main(array<String^> ^ args)
{
   bool stack_semantics = true;

   if (args->Length < 2)
   {
      Console::WriteLine("Usage: file_converter <sourcefile> <destfile>");
      return -1;
   }

   if (stack_semantics)
   {
      // converter is created with stack semantics, so the destructor
      //  (and finalizer) get called when main exits.
      FileConverter converter(args[0]);
      converter.Convert(args[1]);
   }
   else
   {
      // converter used with heap semantics. Destructor is not called,
      // so the file must be closed by calling the Close method. It will not
      // work to close the file from the finalizer, since the StreamWriter
      // object may be in an invalid state.
      FileConverter^ converter = gcnew FileConverter(args[0]);
      converter->Convert(args[1]);
      converter->Close(); // or: delete converter;
   }
}
