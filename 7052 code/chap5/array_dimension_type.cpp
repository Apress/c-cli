// array_dimension_type.cpp

void f(int a[][2]) { }

void g(int a[5][2]) { }

int main()
{
   int native_2d_array[5][2];
   int native_2d_array2[15][2];

   f(native_2d_array);
   f(native_2d_array2);
   g(native_2d_array);
   g(native_2d_array2);
}
