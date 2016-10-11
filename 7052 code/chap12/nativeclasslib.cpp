// nativeclasslib.cpp
// compile with: cl /LD nativeclasslib.cpp

#include <stdio.h>

class __declspec(dllexport) NativeClass 
{
    private:
        int m_member;
    public:
        NativeClass() : m_member(1) { }

        int F( int i )
        {
           // __FUNCSIG__ is a compiler-defined macro evaluating
           // to the current function signature
           printf("%s\n", __FUNCSIG__);
           return m_member + i;
        }

        static NativeClass* CreateObject()
        {
           printf("%s\n", __FUNCSIG__);
           return new NativeClass();
        }

        static void DeleteObject(NativeClass* p)
        {
           printf("%s\n", __FUNCSIG__);
           delete p;
        }
     };
    
// If you do not want to use the obfuscated names, you can use these exports:

extern "C" __declspec(dllexport) NativeClass* CreateObject()
{
   return NativeClass::CreateObject();
}

extern "C" __declspec(dllexport) void DeleteObject(NativeClass* p)
{
   NativeClass::DeleteObject(p);
}

/* The mangled names were obtained by running the command
     link /DUMP /EXPORTS nativeclasslib.dll
   which outputs:

    ordinal hint RVA      name

          1    0 00001000 ??0NativeClass@@QAE@XZ
          2    1 000010D0 ??4NativeClass@@QAEAAV0@ABV0@@Z
          3    2 00001050 ?CreateObject@NativeClass@@SAPAV1@XZ
          4    3 000010A0 ?DeleteObject@NativeClass@@SAXPAV1@@Z
          5    4 00001020 ?F@NativeClass@@QAEHH@Z
          6    5 000010F0 CreateObject
          7    6 00001100 DeleteObject
*/
