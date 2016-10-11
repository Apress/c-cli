// events_custom.cpp
#include <msclr\lock.h>
using namespace System;
using namespace msclr;

ref class Events
{
   public:

      // underlying delegates to use for the events.
      EventHandler^ _start, ^ _exit;

      event EventHandler^ Start
      {
           // Use the += operator to add a function to the
           // (multicast) delegate
           void add(EventHandler^ handler)
           {
               lock lockEvent(this);
               Console::WriteLine(" Adding Start event handler. ");
               _start += handler;
           }
           void remove(EventHandler^ handler)
           {
               lock lockEvent(this);
               Console::WriteLine(" Removing Start event handler. ");
               _start -= handler;
           }

           protected:

              // If the underlying delegate is non-null, invoke the
              // event with the given event arguments.
              void raise(Object^ sender, EventArgs^ args)
              {
                  Console::WriteLine(" Firing Start event. ");
                  if (_start)
                      _start->Invoke(sender, args);
              }
      }

      event EventHandler^ Exit
      {
           void add(EventHandler^ handler)
           {
               lock lockEvent(this);
               Console::WriteLine(" Adding Exit event handler. ");
               _exit += handler;
           }
           void remove(EventHandler^ handler)
           {
               lock lockEvent(this);
               Console::WriteLine(" Removing Exit event handler. ");
               _exit -= handler;
           }
           void raise(Object^ sender, EventArgs^ args)
           {
               Console::WriteLine(" Firing Exit event. ");
               if (_exit)
                  _exit->Invoke(sender, args);
           }
      }

      // Function calls to raise the events from outside the class.
      void RaiseStartEvent()
      {
          Start(this, gcnew EventArgs());
      }

      void RaiseExitEvent()
      {
          Exit(this, gcnew EventArgs());
      }

      // event handler for Start event
      void OnStart(Object^ sender, EventArgs^ args)
      {
         Console::WriteLine("Starting");
      }

      // event handler for Exit event
      void OnExit(Object^ sender, EventArgs^ args)
      {
          Console::WriteLine("Exiting");
      }
};


void f(Events^ e)
{
   // raise event for starting this function
   e->RaiseStartEvent();

   Console::WriteLine("Doing something.");

   // raise event for exiting this function
   e->RaiseExitEvent();
}

int main()
{

    Events^ events = gcnew Events();

    // add the event handlers for Start and Exit
    events->Start += gcnew EventHandler(events, &Events::OnStart);
    events->Exit += gcnew EventHandler(events, &Events::OnExit);

    f(events);

    // remove the event handlers
    events->Start -= gcnew EventHandler(events, &Events::OnStart);
    events->Exit -= gcnew EventHandler(events, &Events::OnExit);
}
