// auto_handle.cpp
#include <msclr\auto_handle.h>

using namespace System;
using namespace msclr;

ref class DBConnection
{
   public:
     bool Open()
     {
        // open a database connection (actual code omitted)
        // ...
        return true;
     }
     void Close()
     {
        // close the database connection
        // ...
     }
};

ref class PlantData
{
     DBConnection^ connection;
     int id;

     PlantData(int i) : id(i)
     {
        if (connection->Open() == true)
        {
          Console::WriteLine("Opened connection for id {0}.", id);
        }
     }

     public:

     static PlantData^ GetPlantData(int id)
     {
         return gcnew PlantData(id);
     }

     void Use()
     {
         Console::WriteLine("Using id {0}.", id);
         // Query database
         // Update records, etc.
     }

     ~PlantData()
     {
        connection->Close();
        Console::WriteLine("Closing connection for id {0}.", id);
     }
};

// Using stack semantics: destructor called.
void f_stack(int i)
{
   auto_handle<PlantData> data = PlantData::GetPlantData(i);
   data->Use();
}

int main()
{
     f_stack(1);
}
