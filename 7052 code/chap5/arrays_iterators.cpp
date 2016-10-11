// arrays_iterators.cpp
using namespace System;
using namespace System::Collections;

int main()
{
   array<DateTime^>^ dateArray = gcnew array<DateTime^>(2);

   dateArray[0] = gcnew DateTime(1970, 12, 18);
   dateArray[1] = gcnew DateTime(1990, 1, 5);

   IEnumerator^ enumerator1 = dateArray->GetEnumerator();
   while ( enumerator1->MoveNext() )
   {
      DateTime^ current = (DateTime^) enumerator1->Current;
      Console::WriteLine( current->ToString("MM/dd/yyyy") );
   }

}
