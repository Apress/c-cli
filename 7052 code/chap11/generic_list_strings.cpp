// generic_list_strings.cpp
using namespace System;
using namespace System::Collections::Generic;

using namespace System;
using namespace System::Collections::Generic;

// ListNode represents a single element in a linked list.
generic <typename T> ref struct ListNode
{
   ListNode<T>(T t) : item(t) { }

   // The item field represents the data in the list.
   T item;
   // The next node in the list;
   ListNode<T>^ next;
};

// List represents a linked list.
generic <typename T> ref class MyList : IEnumerable<ListNode<T>^>
{
   ListNode<T>^ first;

   public:

      property bool changed;

      // Add an item to the end of the list.
      void Add(T t)
      {
         changed = true;
         if (first == nullptr)
         {
            first = gcnew ListNode<T>(t);
         }
         else
         {
            // Find the end.
            ListNode<T>^ node = first;
            while (node->next != nullptr)
            {
               node = node->next;
            }
            node->next = gcnew ListNode<T>(t);
         }
      }

      // Return true if the object was removed,
      // false if it was not found.
      bool Remove(T t)
      {
          changed = true;
          if (first == nullptr)
            return false;
          if (first->item->Equals(t))
          {
             // remove first from list by
             // resetting first
             first = first->next;
             return true;
          }
          ListNode<T>^ node = first;
          while(node->next != nullptr)
          {
             if (node->next->item->Equals(t))
             {
                 // Remove next from list by
                 // leapfrogging it.
                 node->next = node->next->next;
                 return true;
             }
             node = node->next;
          }
          return false;
      }

      property ListNode<T>^ First
      {
         ListNode<T>^ get()
          {
             return first;
          }
      }

   private:
      virtual System::Collections::IEnumerator^ GetEnumerator_NG() sealed
                = System::Collections::IEnumerable::GetEnumerator
      {
         return GetEnumerator();
      }

      virtual IEnumerator<ListNode<T>^>^ GetEnumerator_G() sealed
                = IEnumerable<ListNode<T>^>::GetEnumerator
      {
          return GetEnumerator();
      }

   public:
      IEnumerator<ListNode<T>^>^ GetEnumerator()
      {
          ListEnumerator<T>^ enumerator = gcnew ListEnumerator<T>(this);
          return (IEnumerator<ListNode<T>^>^) enumerator;
      }

      // ListEnumerator is a struct that walks the list, pointing
      // to each element in turn.
      generic <typename T> ref struct ListEnumerator : IEnumerator<ListNode<T>^>
      {
          ListNode<T>^ current;
          MyList<T>^ theList;
          bool beginning;

          ListEnumerator<T>(MyList<T>^ list) : theList(list), beginning(true)
          {
              theList->changed = false;
          }

          private:
             virtual property Object^ Current_NG
             {
                 Object^ get() sealed =
                    System::Collections::IEnumerator::Current::get
                 {
                    return (Object^) Current;
                 }
             }

             virtual property ListNode<T>^ Current_G
             {
                 ListNode<T>^ get() sealed = IEnumerator<ListNode<T>^>::Current::get
                 {
                    return Current;
                 }
             }

          public:

             property ListNode<T>^ Current
             {
                 ListNode<T>^ get()
                 {
                     if (theList->changed)
                        throw gcnew InvalidOperationException();
                     return current;
                 }
             }

             virtual bool MoveNext()
             {
                 if (theList->changed)
                     throw gcnew InvalidOperationException();
                 beginning = false;
                 if (current != nullptr)
                 {
                   current = current->next;
                 }
                 else
                    current = theList->First;

                 if (current != nullptr)
                     return true;
                 else
                     return false;
              }

              virtual void Reset()
              {
                 theList->changed = false;
                 current = theList->First;
              }

              ~ListEnumerator() {}

        }; // end of ListEnumerator
}; // end of MyList


ref class R
{
   String^ name;

   public:

   R(String^ n) : name(n) {}

   virtual String^ ToString() override
   {
      return name;
   }
};

int main()
{
    MyList<R^>^ R_list = gcnew MyList<R^>();

    R_list->Add(gcnew R("test1"));
    R_list->Add(gcnew R("test2"));
    R_list->Add(gcnew R("test3"));

    for each (ListNode<R^>^ node in R_list)
    {
        Console::WriteLine(node->item);
    }
}
