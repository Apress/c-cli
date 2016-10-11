// context_switch.cpp
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#pragma unmanaged
int native_function(wchar_t* str1, wchar_t* str2 )
{
    int i = 0;
    while (*str1++ = *str2++) i++; 
    return i;
}

#pragma managed

wchar_t* random_string(wchar_t* wcs, int n)
{
   for (int i = 0; i < n - 1; i++)
   {
       wcs[i] = (wchar_t) floor(((double) rand() / (double) RAND_MAX * 26)) + L'A';
   }
   return wcs;
}
// try commenting out the pragma above random_string and uncomment this:
// #pragma managed

int main()
{
   wchar_t wcs1[100];
   wchar_t* wcs2 = new wchar_t[100];
   memset(wcs1, 0, 100 * sizeof(wchar_t));
   clock_t t = clock();
   const int num_iter = 100000;
   for (int i = 0; i < num_iter; i++)
   {
     random_string(wcs1, 100);
     native_function(wcs2, wcs1);
   }
   double time_elapsed = (clock()-t)/(double)CLOCKS_PER_SEC;
   printf("total time elapsed: %2.2f seconds\n", time_elapsed);
}

