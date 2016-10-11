interface class IAddition
{
      static IAddition^ operator+(IAddition^, IAddition^);
};

generic <typename T> where T : IAddition
ref class G
{
   T add(T t1, T t2) { return t1 + t2; }
};
