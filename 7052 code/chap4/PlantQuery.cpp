// PlantQuery.cpp

class Recordset;

class DBConnection
{
   public:
      DBConnection()
      {
          // Open the connection
          // ...
      }
      void Query(char* search, Recordset** records)
      {
          // query the database, generate recordset
          // ...
      }
      ~DBConnection()
      {
          // Close the connection
          // ...
      }
};

class PlantData
{
   public:
     static void PlantQuery(char* search, Recordset** records)
     {
         DBConnection connection;
         connection.Query( search, records);
     } // destructor for connection called
};
