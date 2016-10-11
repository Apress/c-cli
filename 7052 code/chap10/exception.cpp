// exception.cpp
using namespace System;

int main()
{

try
{
     bool error = true;
     // other code

     if (error)
     {
          throw gcnew Exception();
     }
}
catch( Exception^ exception)
{
      // code to handle the exception
}
}
