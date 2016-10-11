// reflection_general.cpp

using namespace System;
using namespace System::Reflection;

// A class to reflect upon

ref class Reflector
{
   public:

   // Load an assembly, and print out the methods in the types in the
   // assembly, invoking the specified method on the specified type.
   void LoadAndReflect(String^ assemblyFileName)
   {
      Assembly^ assembly = Assembly::LoadFrom(assemblyFileName);
      array<Type^>^ types = assembly->GetTypes();
      for each (Type^ t in types)
      {
         Console::WriteLine(t->ToString());

         // Get the methods and loop over them.
         array<MethodInfo^>^ methods = t->GetMethods();
         for each (MethodInfo^ method in methods)
         {
             Console::Write("   {0} {1}(", method->ReturnType->ToString(),
                   method->Name);
             // Get the parameters and loop over them.
             array<ParameterInfo^>^ params = method->GetParameters();
             // We don't use for each here because we need to use the index
             // to determine whether a comma is needed.
             for (int i = 0; i < params->Length; i++)
             {
                 ParameterInfo^ param  = params[i];
                 Console::Write("{0} {1}",
                    param->ParameterType->ToString(),
                    param->Name);
                 if (i < params->Length - 1)
                    Console::Write(", ");
             }
             Console::WriteLine(")");
         }
      }
   }
};

int main(array<String^>^ args)
{
   Reflector^ r = gcnew Reflector();
   // Pass the assembly file name and reflect over it.
   for each (String^ s in args)
   {
      Console::WriteLine("Reflection on {0}", s);
      r->LoadAndReflect(s);
   }
}
