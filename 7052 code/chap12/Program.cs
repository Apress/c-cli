// Program.cs
using System;
using System.Collections.Generic;
using System.Text;

class Program
{
   static void Main(string[] args)
   {
      MessageBoxWrapper wrapper = 
         new MessageBoxWrapper("I hope you love this message box!",
           "C# using Native Message Box", MessageBoxTypeEnum.OKCANCEL);
      wrapper.Display();
    }
}
