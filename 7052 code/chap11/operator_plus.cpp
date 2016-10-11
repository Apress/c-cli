template <class T>
ref class A
{
   // assumes T supports the + operator
   T add(T t1, T t2) { return t1 + t2; }
};
