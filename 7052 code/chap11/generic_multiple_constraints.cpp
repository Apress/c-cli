// generic_multiple_constraints.cpp
using namespace System;

interface class I;
ref class C;

// T must have a public default constructor and
// T must inherit from C and
// T must implement I.
generic <class T>
where T : gcnew(), C, I
void F(T t)
{
   // ...
}

interface class IKey;

// Use multiple where clauses to specify
// constraints for multiple type parameters.
generic <typename Key, typename Value>
where Key : IKey
where Value : value class
ref class Dictionary
{
   // ...
};
