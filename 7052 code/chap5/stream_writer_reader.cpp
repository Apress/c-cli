// stream_writer_reader.cpp

using namespace System;
using namespace System::IO;

int main()
{

   StreamWriter^ sw = gcnew StreamWriter("textfile.txt");
   sw->WriteLine("Can code be poetry?");
   sw->Flush();
   sw->Close();

   // The File class's CreateText static method is used to
   // create a text file
   StreamWriter^ sw2 = File::CreateText("newtextfile.txt");

   StreamReader^ sr = gcnew StreamReader("textfile.txt");
   String^ line;
   // Read each line and write it out to the console.
   while ((line = sr->ReadLine()) != nullptr)
   {
      Console::WriteLine(line);
   }
}