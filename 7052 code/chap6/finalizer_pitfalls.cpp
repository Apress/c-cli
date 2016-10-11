// finalizer_pitfalls.cpp
#using "System.dll"
#using "System.Data.dll"

using namespace System;
using namespace System::Data::SqlClient;

ref class DataConnection
{
   SqlConnection^ conn;

   public:

   DataConnection()
   {
      conn = gcnew SqlConnection(
             "Server=(local);Uid=sa;Pwd=****;Initial Catalog=master");
      conn->Open();
   }

   // ... more code ...

   ~DataConnection()
   {
      this->!DataConnection();
   }

   !DataConnection()
   {
      try {
        Console::WriteLine("Closing connection...");
        conn->Close();
      }
      catch(Exception^ e)
      {
         Console::WriteLine("Error occurred! " + e->Message);
      }
   }

};

void UseData()
{
   DataConnection connection1;
   DataConnection^ connection2 = gcnew DataConnection();
   // use the connection

}

int main()
{
   UseData();
   // Force a garbage collection, to illustrate a point
   GC::Collect();
}
