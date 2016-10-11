// runtimewrappedexception.cs
using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.CompilerServices;

class Program
{
   static void Main(string[] args)
   {
      try
      {
         R.TrySomething();
      }
      catch (RuntimeWrappedException e)
      {
         String s = (String)e.WrappedException;
         Console.WriteLine(e.Message);
         Console.WriteLine(s);
       }
   }
}
