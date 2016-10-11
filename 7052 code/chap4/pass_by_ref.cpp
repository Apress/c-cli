// pass_by_ref.cpp
using namespace System;

value class Pair
{
  public:
     int x;
     int y;
};

void swap_values(Pair% pair)
{
    int temp = pair.x;
    pair.x = pair.y;
    pair.y = temp;
}

int main()
{
   Pair p;
   p.x = 5;
   p.y = 3;
   Console::WriteLine("{0} {1}", p.x, p.y);
   swap_values(p);
   Console::WriteLine("{0} {1}", p.x, p.y);
}
