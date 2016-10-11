int j = 4 ;
void f( int *& pi )
{
   // the pointer is redirected to a different variable
   pi = &j ;
}

int main() {
   int i = 2 ;
   int *p = &i;
   f( p );
   // i is still 2 here; it was not affected by the function call
}
