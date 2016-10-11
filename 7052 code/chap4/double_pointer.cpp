// double_pointer.cpp
#include <malloc.h>

int newstring(void** new_buffer)
{
   *new_buffer = malloc( 1024 );
   if (! *new_buffer) return -1;
   return 1;
}
