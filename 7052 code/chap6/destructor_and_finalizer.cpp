// destructor_and_finalizer.cpp

ref class ManagedResource
{
   public:
     void Free() { /* free resource */ }
};

class NativeResource
{
   public:
     void Free() { /* free resource */ }
};

ref class R
{
    ManagedResource^ resource1;
    NativeResource* nativeResource;

    public:
      ~R()
      {
         // you may clean up managed resources that you want to free up promptly
         // here. If you don't, they WILL eventually get cleaned up by the garbage
         // collector.
         // If the destructor is NOT called, the GC will eventually clean
         // them up.
         resource1->Free();
         this->!R();
      }
      !R()
      {
           // clean up unmanaged resources that the
           // garbage collector doesn't know how to clean up.
           // That code shouldn't be in the destructor because
           // the destructor might not get called
           nativeResource->Free();
      }
};
