// debug_print.cpp
using namespace System;

void DebugPrint(Object^ obj)
{
   // For debugging purposes, display the type of the object
   // and its string conversion.

   System::Type^ type = obj->GetType();
   Console::WriteLine("Type: {0} Value: {1}", type->ToString(),
      obj->ToString() );

}

int main()
{

    int i = 56;
    DebugPrint(i);

    String^ s = "Time flies like an arrow; fruit flies like a banana.";
    DebugPrint(s);
}