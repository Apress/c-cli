// finalizer.cpp
using namespace System;

ref class R
{
   int ID;

   public:

   R(int id) : ID(id)  { Console::WriteLine("R constructor {0}", ID); }
   ~R() { Console::WriteLine("R destructor {0}", ID); }
   !R() { Console::WriteLine("R finalizer {0}", ID); }
};

void MakeObjects()
{
   R^ r;
   R r1(0);
   for (int i = 1; i < 7; i++)
   {
      r = gcnew R(i);
   }
}

int main()
{
   MakeObjects();
   // Normally, you should avoid calling GC::Collect and forcing garbage
   // collection rather than letting the garbage collection thread determine
   // the best time to collect; I do it here to illustrate a point
   GC::Collect();
}
