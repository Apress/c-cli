// lvalues.cpp

int main()
{
   int i;
   int j = 10;  // "int j" is an lvalue
   i = 15;      // "i" is an lvalue

   15 = 10;     // error: 15 is NOT an lvalue!
}
