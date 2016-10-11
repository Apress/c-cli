// sender_receiver.cpp
using namespace System;

// This class generates an event
ref class EventSender
{

   public:

   event EventHandler^ MyEvent;

   void Fire(EventArgs^ args)
   {
      // raise event for starting this function
      MyEvent(this, args);

   }
};


// This class will handle the event
ref class EventReceiver
{
   public:

      // event handler for Start event
      void OnMyEvent(Object^ sender, EventArgs^ args)
      {
         Console::WriteLine("My Event");
      }

      void SetUpToReceive(EventSender^ sender)
      {
          // add the event handler
          sender->MyEvent += gcnew EventHandler(this, &EventReceiver::OnMyEvent);
      }

};


int main()
{
    EventReceiver^ receiver = gcnew EventReceiver();
    EventSender^ sender = gcnew EventSender();

    // configure the receiver to listen to events
    // from the specified sender.
    receiver->SetUpToReceive(sender);

    EventArgs^ args = gcnew EventArgs();
    sender->Fire(args);
}
