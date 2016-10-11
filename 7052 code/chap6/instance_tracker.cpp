// instance_tracker.cpp

using namespace System;
using namespace System::Collections::Generic;

// ref type
ref class R
{
    static List<R^>^ instanceTrackingList;

    static R()
    {
       instanceTrackingList = gcnew List<R^>;
    }

    public:

    R(String^ s)
    {
       Label = s;
       instanceTrackingList->Add( this );
    }

    property String^ Label;

    static int EnumerateInstances()
    {
       int i = 0;
       for each (R^ r in instanceTrackingList)
       {
           i++;
           Console::WriteLine( r->Label );
       }
       return i;
    }

    ~R()   // destructor
    {
       // When invoking a function through the this pointer,
       // use the indirection operator (->)
       this->!R();
    }

    !R()   // finalizer
    {
       instanceTrackingList->Remove( this );
    }

    // etc.
};

int main()
{
    R r1("ABC");
    R^ r2 = gcnew R("XYZ");

    int count = R::EnumerateInstances();
    Console::WriteLine("Object count: " + count);

    delete r2;
    count = R::EnumerateInstances();
    Console::WriteLine("Object count: " + count);
}
