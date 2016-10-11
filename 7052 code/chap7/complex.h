// complex.h
using namespace System;

class Complex
{
   double re;
   double im;

   public:

     Complex() : re(0.0), im(0.0) { }

     Complex(double real, double imag) : re(real), im(imag) { }

     // allow a complex number to be created from a double
     Complex(double real) : re(real), im(0.0) { }

     Complex(const Complex& c)
     {
         this->re = c.re; this->im = c.im;
     }

     // assignment operator
     Complex& operator=(const Complex& c)
     {
         this->re = c.re; this->im = c.im;
         return *this;
     }

     // equality operator for comparing two complex numbers
     bool operator==(const Complex& c)
     {
         return (this->re == c.re && this->im == c.im);
     }

     // unary minus
     Complex operator-()
     {
          return Complex(-re, im);
     }

     // add a complex number to a complex number
     Complex operator+(const Complex& rhs)
     {
         return Complex(this->re + rhs.re, this->im + rhs.im);
     }
     // add a complex number to a complex number
     Complex operator+(double d)
     {
         return Complex(this->re + d, this->im);
     }
     // add a double and a complex number
     // this must be a global friend operator
     friend Complex operator+(double d, Complex c)
     {
         return Complex(c.re + d, c.im);
     }

     // ditto for ambition, distraction, uglification and derision...

};
