using namespace System;

namespace MonsterExtensions
{

public ref class Attack
{
    
};

public enum class AttackTypeEnum
{
   Type1,
   Type2
};

public ref class AnimationSequence2D
{

};

public interface class IMonster
{

     property String^ Name;
     property int Strength;
     property AnimationSequence2D^ Frames;
     Attack^ GenerateAttack(AttackTypeEnum attacktype);
     void DefendAttack(Attack^ attack);
     // etc.
};

}