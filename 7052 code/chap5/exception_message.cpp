
using namespace System;
using namespace System::IO;

int main()
{

   String^ filename = "textfile.txt";
   try
   {
      // Another way of creating a StreamReader class is with
      // static methods of the File class.
      StreamReader^ sr2 = File::OpenText(filename);

      String^ line;
      // Read each line and write it out to the console.
      while ((line = sr2->ReadLine()) != nullptr)
      {
         Console::WriteLine(line);
      }
   }
   catch(IOException^ e)
   {
       Console::WriteLine("Exception! {0}", e->Message );
   }
}
