#using "extension_monster.dll"

using namespace System;
using namespace MonsterExtensions;
using namespace System::Reflection;

IMonster^ GetExtensionMonsterInterface(String^ userMonsterAssemblyFileName,
     String^ userMonsterClassName)
{
   Assembly^ userMonsterAssembly = Assembly::LoadFrom( userMonsterAssemblyFileName );
   IMonster^ userMonster = (IMonster^) userMonsterAssembly->CreateInstance(
        userMonsterClassName );
   return userMonster;
}

int main()
{
   IMonster^ monster = GetExtensionMonsterInterface("mymonster.dll", "MyMonster");

   Attack^ attack = monster->GenerateAttack(AttackTypeEnum::Type1);
};