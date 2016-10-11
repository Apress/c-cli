// pinvoke_thiscall.cpp
// compile with: cl /clr:safe pinvoke_thiscall.cpp

using namespace System;
using namespace System::Text;
using namespace System::Runtime::InteropServices;

namespace NativeLib
{
    [ DllImport( "nativeclasslib.dll", 
    EntryPoint="?F@NativeClass@@QAEHH@Z", 
    CallingConvention=CallingConvention::ThisCall )]
    extern int F( IntPtr ths, int i );

    // static NativeClass* NativeClass::CreateObject();
    [DllImport( "nativeclasslib.dll", EntryPoint=
                "?CreateObject@NativeClass@@SAPAV1@XZ" )]
    extern IntPtr CreateObject();

    // static void NativeClass::DeleteClass( NativeClass* p )
    [ DllImport( "nativeclasslib.dll", EntryPoint=
                 "?DeleteObject@NativeClass@@SAXPAV1@@Z" )]
    extern void DeleteObject( IntPtr p ); 
}


int main()
{
    IntPtr ptr = NativeLib::CreateObject();
    int result = NativeLib::F( ptr, 50 ); 
    Console::WriteLine( "Return value: {0} ", result );
    NativeLib::DeleteObject( ptr );
}
