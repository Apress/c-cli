// events_custom2.cpp
#include <msclr\lock.h>
using namespace System;
using namespace msclr;

delegate void EventProcessor(String^ eventString);

ref class Events
{
   public:

      // underlying delegates to use for the events.
      EventProcessor^ _start, ^ _exit;

      event EventProcessor^ Start
      {
           void add(EventProcessor^ handler)
           {
               lock lockEvents(this);
               Console::WriteLine(" Adding Start event handler. ");
               _start += handler;
           }
           void remove(EventProcessor^ handler)
           {
               lock lockEvents(this);
               Console::WriteLine(" Removing Start event handler. ");
               _start -= handler;
           }

           protected:

              void raise(String^ eventString)
              {
                  Console::WriteLine(" Firing Start event. ");
                  if (_start)
                      _start->Invoke(eventString);
              }
      }

      event EventProcessor^ Exit
      {
           void add(EventProcessor^ handler)
           {
               lock lockEvents(this);
               Console::WriteLine(" Adding Exit event handler. ");
               _exit += handler;
           }
           void remove(EventProcessor^ handler)
           {
               lock lockEvents(this);
               Console::WriteLine(" Removing Exit event handler. ");
               _exit -= handler;
           }
           void raise(String^ eventString)
           {
               Console::WriteLine(" Firing Exit event. ");
               if (_exit)
                  _exit->Invoke(eventString);
           }
      }

      // Function calls to raise the events from outside the class.
      void RaiseStartEvent(String^ eventString)
      {
          Start(eventString);
      }

      void RaiseExitEvent(String^ eventString)
      {
          Exit(eventString);
      }

      // event handler for Start event
      void OnStart(String^ eventString)
      {
         Console::WriteLine("Starting: " + eventString);
      }

      // event handler for Exit event
      void OnExit(String^ eventString)
      {
          Console::WriteLine("Exiting: " + eventString);
      }
};

void f(Events^ e)
{
   // raise event for starting this function
   e->RaiseStartEvent("Start event occurred!");

   Console::WriteLine("Doing something.");

   // raise event for exiting this function
   e->RaiseExitEvent("Exit event occurred.");
}

int main()
{

    Events^ events = gcnew Events();

    // add the event handlers for Start and Exit
    events->Start += gcnew EventProcessor(events, &Events::OnStart);
    events->Exit += gcnew EventProcessor(events, &Events::OnExit);

    f(events);

    // remove the event handlers
    events->Start -= gcnew EventProcessor(events, &Events::OnStart);
    events->Exit -= gcnew EventProcessor(events, &Events::OnExit);
}
