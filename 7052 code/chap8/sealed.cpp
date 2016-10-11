// sealed.cpp

ref class C sealed
{
};

ref class B : C  // Error: cannot inherit from a sealed class.
{
};
