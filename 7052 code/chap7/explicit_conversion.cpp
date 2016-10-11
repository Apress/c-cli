// explicit_conversion.cpp

using namespace System;

value class BigIntExplicit
{
   __int64 m_i;

   public:

   explicit BigIntExplicit(int i) : m_i(i)
   { }

   explicit operator int()
   { return m_i; }

   explicit static operator BigIntExplicit(int i)
   { return BigIntExplicit(i); }

   void takeBigIntExplicit(BigIntExplicit b) {}
};

value class BigIntImplicit
{
   __int64 m_i;

   public:

   BigIntImplicit(int i) : m_i(i)
   { }

   operator int()
   { return m_i; }

   static operator BigIntImplicit(int i)
   { return BigIntImplicit(i); }

   void takeBigIntImplicit(BigIntImplicit b) {}
};

int main()
{
   BigIntExplicit b_exp(400);
   BigIntImplicit b_imp(500);

   int i = safe_cast<int>( b_exp );  // OK: requires explicit cast

   int j = b_imp;    // OK: implicit

   // int cannot implicitly be converted to BigInt1 and BigInt2
   // with the constructor; instead, you define the static conversion operator
   // this is different from standard C++, which uses the constructor
   // for such implicit conversions.
   b_exp.takeBigIntExplicit(safe_cast<BigIntExplicit>(i));
   b_imp.takeBigIntImplicit(j);
}
