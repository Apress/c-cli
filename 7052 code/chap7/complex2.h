// complex.h
using namespace System;

value class Complex
{
   double re;
   double im;

   public:

     Complex(double real, double imag) : re(real), im(imag)
     { }

     // unary minus
     Complex operator-()
     {
          return Complex(-re, im);
     }

     // Addition of two complex numbers
     // Could also be defined as a member operator
     static Complex operator+(Complex c1, Complex c2)
     {
         return Complex(c1.re + c2.re, c1.im + c2.im);
     }
     // This cannot be a member operator, since a double is on the left
     static Complex operator+(double d, Complex c)
     {
         return Complex(c.re + d, c.im);
     }
     // If Complex is the first argument, this could also be
     // a member operator
     static Complex operator+(Complex c, double d)
     {
         return Complex(c.re + d, c.im);
     }

     // etc.

};
