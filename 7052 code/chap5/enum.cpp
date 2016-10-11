// enum.cpp

enum class Flavor
{
   Vanilla,
   Chocolate,
   Strawberry
};

int main()
{
   // The enum variable may be a handle
   // or a stack variable. If used as a handle,
   // it's a boxed value type.

   // The enum value, Vanilla, is
   // scoped by the enum class name
   Flavor^ flavor_handle = Flavor::Vanilla;
   Flavor flavor_stack = Flavor::Vanilla;
}
