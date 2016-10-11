// identifier.cpp
using namespace System;

int main()
{
   int __identifier(switch) = 10;

   __identifier(switch)++;

   switch( __identifier(switch) )
   {
      case 10:
         break;
      case 11:
         Console::WriteLine("Switch is {0}", __identifier(switch));
         break;
      default:
         break;
   }

}
