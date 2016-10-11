
#using "extension_monster.dll"

using namespace System;
using namespace MonsterExtensions;

public ref class MyMonster : IMonster
{
   public:

     virtual property String^ Name;
     virtual property int Strength;
     virtual property AnimationSequence2D^ Frames;


   virtual Attack^ GenerateAttack(AttackTypeEnum attacktype)
   {
      return gcnew Attack();
   }
   virtual void DefendAttack(Attack^ attack)
   {
   }
};