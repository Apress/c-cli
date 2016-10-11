// getlasterror.cpp

#using "System.dll"

using namespace System;
using namespace System::ComponentModel; // for Win32Exception
using namespace System::Runtime::InteropServices; 

[DllImport("kernel32.dll", SetLastError=true)] 
extern bool SetVolumeLabel(String^ lpRootPathName, String^ lpVolumeName); 

bool TestGetLastWin32Error()
{ 
   if (SetVolumeLabel("BAD:\\", "VolumeName")) 
   {
      System::Console::WriteLine("Success!"); 
      return true;
   }
   else
   {
      throw gcnew Win32Exception(Marshal::GetLastWin32Error()); 
   } 
   return false;
} 

int main()
{
   try
   {
      TestGetLastWin32Error();
   }
   catch(Win32Exception^ e)
   {
      Console::WriteLine(e->ToString());
   }
}
