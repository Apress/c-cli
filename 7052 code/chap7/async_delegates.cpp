// async_delegates.cpp

using namespace System;
using namespace System::Threading;

ref class R
{
public:
   property String^ Value;

   R(String^ s) { Value = s; }
};

delegate void QueryFunc(String^, R^);

ref class Document
{

   IAsyncResult^ result;
   R^ m_r;

   public:

      Document(String^ s) { m_r = gcnew R(s); }

   // query the database
   void Query(String^ queryString, R^ r)
   {
       // execute a long query
       r->Value = "New Value";
   }

   void InitiateQuery(String^ queryString)
   {
      QueryFunc^ qf = gcnew QueryFunc(this, &Document::Query);
      Console::WriteLine(m_r->Value);
      result = qf->BeginInvoke(queryString, m_r,
                               gcnew AsyncCallback(this, &Document::ProcessResult),
                               qf);
   }

   bool IsQueryCompleted()
   {
      return result->IsCompleted;
   }

   // This function gets called when the asynchronous call
   // completes.
   void ProcessResult(IAsyncResult^ result)
   {
      // Retrieve the delegate.
      QueryFunc^ caller = (QueryFunc^) result->AsyncState;

      // get the data back (fill in DataSet parameter)
      caller->EndInvoke(result);
      Console::WriteLine(m_r->Value);
   }

   void UseData()
   {
      // do something...
   }

};

int main()
{
   Document doc("Old Value");
   doc.InitiateQuery("SELECT * FROM Plants WHERE Plant.Genus = 'Lycopersicon'");
   // do other work while the query executes

   // poll for completion
   while (! doc.IsQueryCompleted() )
   {
       Thread::Sleep(100);
   }

   // do work with the data.

   doc.UseData();

}
