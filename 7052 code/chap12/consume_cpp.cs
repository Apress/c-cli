// consume_cpp.cs
// compile with: csc /r:global_function.dll consume_cpp.cs

using G;

class C
{
   public static void Main()
   {
      // FGlobal();    // error: global functions not available in C#
      R.FMember();     // OK
   }  
};
