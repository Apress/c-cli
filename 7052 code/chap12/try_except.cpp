// try_except.cpp
#include <stdio.h>
#include <windows.h> // for EXCEPTION_INT_DIVIDE_BY_ZERO
#include <excpt.h>

using namespace System;
using namespace System::Runtime::InteropServices;

#pragma unmanaged
void generate_SEH_exception()
{
   int i = 0;
   // divide by zero generates an SEH exception
   int x = 2 / i;
}

void generate_AV()
{
   int *pn = 0;
   int n = *pn; // generates an Access Violation
}

int filter_div0(unsigned int code, struct _EXCEPTION_POINTERS *ep)
{

   if (code == EXCEPTION_INT_DIVIDE_BY_ZERO)
   {
      return EXCEPTION_EXECUTE_HANDLER;
   }
   else
   {
      return EXCEPTION_CONTINUE_SEARCH;
   };
}

// This must be a native function because __try/__except is not
// allowed in the same function as code that uses try/catch
void try_except(bool bThrowUnhandledAV)
{
   __try
   {
      if (bThrowUnhandledAV)
         generate_AV();
      else
         generate_SEH_exception();
   }
   __except( filter_div0(GetExceptionCode(), GetExceptionInformation()))
   {
      printf_s("Divide by zero exception caught via SEH __except block.");
   }
}

#pragma managed

int main(array<String^>^ args)
{
   if (args->Length < 1)
   {
     Console::WriteLine("Usage: try_except [NET|SEH|AV]");
     return -1;
   }
   if (args[0] == "NET") // Demonstrate catching SEH as a .NET Exception
   {
      try
      {
         generate_SEH_exception();
      }
      catch(DivideByZeroException^ e)
      {
         Console::WriteLine(e->ToString());
      }
   }
   else if (args[0] == "SEH")  // Demonstrate handling SEH exception natively
   {
      // call native function with try/except block
      // and filters out division by zero exceptions
      try_except(false);
   }
   else if (args[0] == "AV")  // Demonstrate filtering of what exceptions to handle
                              // natively and what to allow through
   {
     try 
     {
        // AV's, however, are not filtered and are allowed
        // to propagate to managed code
        try_except(true);
     }
     catch(AccessViolationException^ e)
     {
        Console::WriteLine(e->ToString());
     }
   }
}
