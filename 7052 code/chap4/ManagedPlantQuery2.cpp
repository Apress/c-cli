// ManagedPlantQuery2.cpp
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
/*      Recordset^ Query(String^ search)
      {
          // query the database, generate recordset
          // and return pointer to recordset
          // ...
      }
*/
      void Query(String^ search, Recordset^% records)
      {
          // query the database, generate recordset
          // and set the records handle to point to it
          records = gcnew Recordset();
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
         DBConnection connection;
         return connection.Query( search);
     }
*/
     static Recordset^ PlantQuery(String^ search)
     {
         DBConnection connection;
         Recordset^ records;
         connection.Query( search, records );
         return records;
     }

};
