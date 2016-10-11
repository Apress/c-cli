// arrays_interior_ptr.cpp
using namespace System;

ref class Buf
{
    // ...
};

int main()
{
   array<Buf^>^ array_of_buf = gcnew array<Buf^>(10);

   // Create a Buf object for each array position
   for each (Buf^ bref in array_of_buf)
   {
      bref = gcnew Buf();
   }

   // create an interior pointer to elements of the array
   interior_ptr<Buf^> ptr_buf;

   // loop over the array with the interior pointer
   // using pointer arithmetic on the interior pointer
   for (ptr_buf = &array_of_buf[0]; ptr_buf <= &array_of_buf[9]; ptr_buf++)
   {
      // dereference the interior pointer with *
      Buf^ buf = *ptr_buf;
      // use the Buf class
   }
}
