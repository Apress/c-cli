// custom_attribute.cpp

using namespace System;

// This attribute is applied to custom attributes and indicates the targets for
// the attribute, among other things. In this case, we accept the defaults.
[AttributeUsageAttribute(AttributeTargets::All)]
public ref class OwnerAttribute : Attribute
{
   public:
      property String^ DevOwner;
      property String^ TestOwner;
      property String^ PMOwner;
      property String^ DocOwner;
      property DateTime^ CreationDate;

      OwnerAttribute()
      { }

      OwnerAttribute(String^ _DevOwner, String^ _TestOwner,
                     String^ _PMOwner, String^ _DocOwner)
      {
         DevOwner = _DevOwner;
         TestOwner = _TestOwner;
         PMOwner = _PMOwner;
         DocOwner = _DocOwner;
      }
};

// Parameter order
[ Owner("John Smith", "Jane Doe", "Hubert Eliason", "Edgar Odell")]
ref class C1
{
   // etc.
};

// Using named parameters
[ Owner(DevOwner="John Smith") ]
ref class C2
{
   // etc.
};
