// interface_list.cpp

using namespace System;

interface class IA {};
interface class IB {};

ref class Base : IA   // OK
{ };

ref class Derived : Base, IA  // OK : Base class first
{ };

ref class A : Object, IA  // OK: Object may be explicitly stated.
{ };

value class V : ValueType, IA  // OK: Value class inherits from ValueType.
{ };

ref class B : IB, Base  // OK. Base class need not appear first (as in C#).
{ };
