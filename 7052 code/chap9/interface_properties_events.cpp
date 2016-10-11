// interface_properties_events.cpp
using namespace System;

interface class I
{
   property int P1;
   event EventHandler^ E;

   property int P2
   {
      int get();
      void set(int v);
   }
};

ref class R : I
{
   int value;

   public:

   virtual property int P1;
   virtual event EventHandler^ E;

   virtual property int P2
   {
      int get() { return value; }
      void set(int v) { value = v; }
   }

};
