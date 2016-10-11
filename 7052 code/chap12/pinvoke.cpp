// pinvoke.cpp
using namespace System;
using namespace System::Runtime::InteropServices;

// note the use of managed equivalents of native types
[DllImport("user32.dll", CharSet=CharSet::Auto)]
int MessageBox(IntPtr, String^ text, String^ caption, 
   unsigned int type);

int main()
{
   MessageBox(IntPtr::Zero, "Hello, World!", "Win32 Message Box", 0);
}
