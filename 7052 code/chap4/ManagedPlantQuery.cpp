// ManagedPlantQuery.cpp
using namespace System;

ref class Recordset;

ref class DBConnection
{
   public:
      DBConnection()
      {
          // Open the connection
          // ...
      }
      Recordset^ Query(String^ search)
      {
          // query the database, generate recordset
          // and return handle to recordset
          // ...
      }
      ~DBConnection()
      {
          // Close the connection
          // ...
      }
};

ref class PlantData
{
   public:
/*     static Recordset^ PlantQuery(String^ search)
     {
         DBConnection^ connection = gcnew DBConnection();
         return connection->Query( search );
     }
*/

     static Recordset^ PlantQuery(String^ search)
     {
         DBConnection^ connection = gcnew DBConnection();
         Recordset^ records = connection->Query( search );
         delete connection;
         return records;
     }

};
