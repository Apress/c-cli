// static_const_vs_literal.cpp
// compile with: cl /clr /LD static_const_vs_literal.cpp

public ref class R
{
   public:
      static const int i = 15;
      literal int j = 25;
};
