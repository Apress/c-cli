// custom_attribute2.cpp

using namespace System;

// Specify what targets this attribute may be applied to using the
// AttributeUsageAttribute.
[AttributeUsageAttribute(AttributeTargets::Assembly | AttributeTargets::Class)]
public ref class OwnerAttribute : Attribute
{
   public:
      // Public properties can be used as named parameters.
      property String^ DevOwner;
      property String^ TestOwner;

      OwnerAttribute() { }

};

// Using named parameters
[ Owner(DevOwner="John Smith") ]
ref class C2
{
   // etc.
};


int main()
{
    Attribute^ attribute = Attribute::GetCustomAttribute( C2::typeid,
                              OwnerAttribute::typeid);
    if (attribute != nullptr)
    {
         Console::WriteLine("{0}", attribute);
    }
}
