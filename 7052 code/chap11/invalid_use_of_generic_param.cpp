// invalid_use_of_type_param.cpp

generic <typename T>
ref class G
{
   T t;

   public:

      G()
      {
         t = gcnew T("abc", 100); // Error: T may not have
                                  // a compatible constructor.
         t->F(); // Error: T may not have F.
      }

};
