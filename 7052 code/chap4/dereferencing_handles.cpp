
ref class R
{
   public:

   R() {}
   R(R% r) {}
};

int main()
{
   R^ r_handle = gcnew R();
   R r_auto = *r_handle; // copy ctor used
   R% r_ref = *r_handle; // not copied
}