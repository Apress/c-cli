// cards_enumerable.cpp

using namespace System;
using namespace System::Text;
using namespace System::Collections;

enum class SuitEnum { Diamonds, Clubs, Hearts, Spades };

// Represents a playing card
value struct Card
{
   SuitEnum Suit;
   unsigned int Rank;
   literal int CHAR_HEART = 3; // ASCII heart character
   literal int CHAR_DIAMOND = 4; // ASCII diamond
   literal int CHAR_CLUB = 5; // ASCII club
   literal int CHAR_SPADE = 6;  // ASCII spade

   // Render the two-character card using ASCII card values.
   virtual String^ ToString() override
   {
      StringBuilder^ s = gcnew StringBuilder();
      if (Rank <= 0 || Rank > 13)
         throw gcnew InvalidOperationException();
      else if (Rank < 11)
      {
         s->Append(Rank);
      }
      else
      {
         switch (Rank)
         {
         case 11: // Jack
            s->Append("J");
            break;
         case 12:  // Queen
            s->Append("Q");
            break;
         case 13:  // King
            s->Append("K");
            break;
         default:
            throw gcnew InvalidOperationException();
         }
      }
      switch (Suit)
      {
      case SuitEnum::Clubs:
         s->Append(CHAR_CLUB, 1);
         break;
      case SuitEnum::Hearts:
         s->Append(CHAR_HEART, 1);
         break;
      case SuitEnum::Diamonds:
         s->Append(CHAR_DIAMOND, 1);
         break;
      case SuitEnum::Spades:
         s->Append(CHAR_SPADE, 1);
         break;
      default:
         throw gcnew InvalidOperationException();
      }
      return s->ToString();
   }
};


// Cards: represents a collection of cards
ref class Cards : IEnumerable
{
   array<Card>^ card_array;

   literal int K = 13; // King's ordinal position
   literal int CARDS_IN_DECK = 52; // Cards in the deck
public:
   Cards()
   {
      // Create a standard deck.
      card_array = gcnew array<Card>(CARDS_IN_DECK + 1);
      for (int i = 1; i <= K; i++)
      {
         card_array[i].Suit = SuitEnum::Diamonds;
         card_array[i].Rank = i;
         card_array[i + K].Suit = SuitEnum::Clubs;
         card_array[i + K].Rank = i;
         card_array[i + 2*K].Suit = SuitEnum::Hearts;
         card_array[i + 2*K].Rank = i;
         card_array[i + 3*K].Suit = SuitEnum::Spades;
         card_array[i + 3*K].Rank = i;
      }
   }

   Cards(const Cards% c)
   {
      card_array = gcnew array<Card>(c.card_array->Length);
      for (int i = 0; i < c.card_array->Length; i++)
      {
         card_array[i] = c.card_array[i];
      }
   }

   // Default indexed property. Allows use of
   // Cards[i] syntax to get a card by index.
   property Card default[int]
   {
      Card get(int index)
      {
         return card_array[index];
      }
      void set(int index, Card card)
      {
         card_array[index] = card;
      }
   }

   // The number of cards in this collection
   property int Count
   {
      int get()
      {
         return card_array->Length;
      }
   }

   // Shuffle the cards in this collection.
   void Shuffle()
   {
      // Swap 5000 cards.
      Random^ random = gcnew Random();
      for (int i = 0; i < 5000; i++)
      {
         int card1 = (int)Math::Ceiling(random->NextDouble() * CARDS_IN_DECK);
         int card2 = (int)Math::Ceiling(random->NextDouble() * CARDS_IN_DECK);
         Card temp = this[card1];
         this[card1] =  this[card2];
         this[card2] = temp;
      }
   }

private:
   // IEnumerable::GetEnumerator method
   // Compiler requires a private virtual method to be marked sealed.
   virtual System::Collections::IEnumerator^ GetEnumeratorNonGeneric() sealed
      = System::Collections::IEnumerable::GetEnumerator
   {
      return GetEnumerator();
   }

public:
   // Nonvirtual GetEnumerator method for efficiency; the virtual
   // methods call the nonvirtual method. For each uses the
   // nonvirtual method.
   IEnumerator^ GetEnumerator()
   {
      return (IEnumerator^) gcnew CardEnumerator(this);
   }

   // nested enumerator class
   ref class CardEnumerator : IEnumerator
   {
      int current;
      Cards^ cards;

   public:
      CardEnumerator(Cards^ cards_in)
      {
         // Snapshot the collection by calling the copy constructor.
         cards = gcnew Cards(*cards_in);
         // The enumerator should always start *before* the first element, so
         // in a zero-based collection that is -1, but here it is 0.
         current = 0;
      }

   private:
      // implements the IEnumerator Current property
      virtual property Object^ _Current
      {
         // Use explicit interface implementation syntax on the get
         // method, not the property. The compiler requires a private
         // virtual method to be marked "sealed".
         Object^ get() sealed = System::Collections::IEnumerator::Current::get
         {
            return Current;
         }
      }

   public:

      // nonvirtual Current property for maximum efficiency
      property Card Current
      {
         Card get()
         {
            if (current <= 0 || current >= cards->Count )
               throw gcnew InvalidOperationException();
            return cards[current];
         }
      }

      // Implements the IEnumerator::MoveNext method
      virtual bool MoveNext()
      {
         current++;
         if (current <= 0 || current > cards->Count)
            throw gcnew InvalidOperationException();
         else
            return current < cards->Count;
      }

      // implements the IEnumerator::Reset method
      virtual void Reset()
      {
         current = 0;
      }
   };

};

void PrintAll(Cards^ deck)
{
   for each (Card c in deck)
   {
       Console::Write("{0} ", c, c.Rank, c.Suit);
       // has no effect on iteration since collection is snapshot
       // but deck will remain shuffled when next used
       deck->Shuffle();
   }
   Console::WriteLine();
}

int main()
{
   Cards^ deck = gcnew Cards();
   PrintAll(deck);
   PrintAll(deck);
}
