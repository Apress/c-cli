// message_comparable_generic.cpp

using namespace System;

enum class SortByEnum
{
   SortByDate,
   SortByFrom,
   SortBySubject
};

ref class Message : IComparable<Message^>
{
   public:

   static property SortByEnum SortCriterion;

   property DateTime DateReceived;
   property String^ From;
   property String^ Subject;
   property String^ Body;

   Message(DateTime dt, String^ from, String^ subject, String^ body)
   {
      DateReceived = dt;
      From = from;
      Subject = subject;
      Body = body;
   }

   virtual int CompareTo(Message^ msg)
   {

       switch ( SortCriterion )
       {
           case SortByEnum::SortByDate:
              return this->DateReceived.CompareTo(msg->DateReceived);
           case SortByEnum::SortByFrom:
              return this->From->CompareTo(msg->From);
           case SortByEnum::SortBySubject:
              return this->Subject->CompareTo(msg->Subject);
           default:
              throw gcnew InvalidOperationException();
       }

   }

   // other methods...

};

// Print the message headers in sorted order.
void PrintHeaders(array<Message^>^ messages, SortByEnum sortOrder)
{
   Message::SortCriterion = sortOrder;
   Array::Sort(messages);

   for (int i = 0; i < messages->Length; i++)
   {
       Console::WriteLine("Received: {0} From: <{1}> Subject: {2}",
           messages[i]->DateReceived, messages[i]->From,
           messages[i]->Subject );
   }
   Console::WriteLine();
}


int main()
{
   // Create some messages.
   array<Message^>^ message_array =
   {
      gcnew Message( DateTime(2006, 1, 12), "Nancy Carlisle", "Dog Jokes", ""),
      gcnew Message( DateTime(2006, 1, 15), "George Jones", "Bark mulch order", ""),
      gcnew Message( DateTime(2006, 1, 2), "George Jones", "Bark mulch offer", ""),
      gcnew Message( DateTime(2005, 12, 31), "Jeni Hogenson",
                     "Wedding Anniversary", "")
   };

   PrintHeaders(message_array, SortByEnum::SortByDate);
   PrintHeaders(message_array, SortByEnum::SortByFrom);
   PrintHeaders(message_array, SortByEnum::SortBySubject);

}
