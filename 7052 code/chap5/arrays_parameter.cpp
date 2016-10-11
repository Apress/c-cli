// arrays_parameter.cpp
using namespace System;

// using an array as an argument

void set_to_one(int i, array<int>^ array_arg)
{
   // change the array inside this function
   array_arg[i] = 1;
}

int main()
{
    array<int>^ array1 = { 0, 1 };
    set_to_one(0, array1);

    // The output here is " 1 1", indicating that the array
    // change is made to the same array
    Console::WriteLine(" {0} {1}", array1[0], array1[1]);

}
