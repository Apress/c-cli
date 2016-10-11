// consume_outattr.cs
// compile with: /r:outattribute.dll

using System;
using OutAttrClass;

public class C
{

   public static void Main()
   {
       C1 c1 = new C1();
       String str = "old value";
       c1.Func(out str);
       Console.WriteLine(str);
   }
};
