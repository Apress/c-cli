// eventargs.cpp
using namespace System;

ref class MyEventArgs : EventArgs
{
   public:
     property String^ Info;

     MyEventArgs(String^ info)
     {
        Info = info;
     }
};

delegate void MyEventHandler(Object^ sender, MyEventArgs^ args);

// This class generates an event
ref class EventSender
{

   public:

   event MyEventHandler^ MyEvent;

   void Fire(MyEventArgs^ args)
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
      void OnMyEvent(Object^ sender, MyEventArgs^ args)
      {
         Console::WriteLine("My Event with info: " + args->Info );
      }

      void SetUpToReceive(EventSender^ sender)
      {
          // add the event handler
          sender->MyEvent += gcnew MyEventHandler(this, &EventReceiver::OnMyEvent);
      }

};


int main()
{
    EventReceiver^ receiver = gcnew EventReceiver();
    EventSender^ sender = gcnew EventSender();

    // configure the receiver to listen to events
    // from the specified sender.
    receiver->SetUpToReceive(sender);

    MyEventArgs^ myargs = gcnew MyEventArgs("abc");
    sender->Fire(myargs);
}
