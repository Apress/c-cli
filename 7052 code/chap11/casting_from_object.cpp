// casting_from_object.cpp
using namespace System;
using namespace System::Collections;

ref class Book
{
   public:
     Book()
     { }
     Book(String^ _title) { Title = _title; }
     property String^ Title;
};

int main()
{
   ArrayList^ theList = gcnew ArrayList();

   theList->Add( gcnew Book("Of Mice and Men") );

   // Use a cast to retrive an object from the list
   // and convert to the appropriate type.
   Book^ book = safe_cast<Book^>( theList[0] );

   Console::WriteLine("OK. The object was retrieved and the title is "
                      + book->Title );

   // Now try putting an object of the wrong type
   // in the list and retrieving it using the same
   // method.

   theList->Add( gcnew String("bad data"));
   try
   {
      book = safe_cast<Book^>( theList[1] );
   }
   catch(InvalidCastException^ e)
   {
      Console::WriteLine("An object of the wrong type was put on the list.");
   }
}
