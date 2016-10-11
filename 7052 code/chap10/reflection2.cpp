// reflection2.cpp

using namespace System;
using namespace System::Reflection;

// A class to reflect upon

ref class Reflector
{
   public:

   void TestDynamicCall(String^ greeting)
   {
      Console::Beep();
      Console::WriteLine(greeting);
      Console::WriteLine("Dynamic Call succeeded!");
   }

   // Load an assembly and invoke the specified method on the specified type.
   void LoadAndReflect(String^ assemblyFileName, String^ typeName,
                       String^ methodName, array<Object^>^ parameterList)
   {
      // Load the assembly.
      Assembly^ assembly = Assembly::LoadFrom(assemblyFileName);

      // Get the type.
      Type^ t= assembly->GetType(typeName);

      // Get the method of interest.
      MethodInfo^ method = t->GetMethod(methodName);

      // Create an instance of the object.
      Object^ obj = Activator::CreateInstance(t);

      // Invoke the method.
      method->Invoke(obj, parameterList);

   }
};

int main()
{
   Reflector r ;
   // Pass the assembly file name, class name, and method name, and the
   // parameter list.
   array<Object^>^ params = gcnew array<Object^> { "Hello!" };
   r.LoadAndReflect("reflection2.exe", "Reflector", "TestDynamicCall", params);
}
