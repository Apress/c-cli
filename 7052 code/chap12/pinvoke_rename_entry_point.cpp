// pinvoke_rename_entry_point.cpp

#using "System.Windows.Forms.dll"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Windows::Forms;

[DllImport("user32.dll", CharSet=CharSet::Auto, EntryPoint="MessageBox")]
int NativeMessageBox(IntPtr, String^ text, String^ caption, 
   unsigned int type);

int main()
{
   NativeMessageBox(IntPtr::Zero, "Hello, World!", "Win32 Message Box", 0);
   MessageBox::Show("Hello, Universe!", "Managed Message Box");
}
