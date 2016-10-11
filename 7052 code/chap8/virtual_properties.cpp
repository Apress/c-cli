// virtual_properties.cpp
using namespace System;

ref class Base
{
   public:

   virtual property int Prop;
};

ref class Derived : Base
{
   int prop;

   public:

   virtual property int Prop
   {
      int get() override { return prop; }
      void set(int value) override { prop = value; }
   }

};
