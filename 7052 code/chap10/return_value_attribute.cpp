
ref class ReturnType {};

ref class ReturnValueAttribute : System::Attribute {};

[ returnvalue: ReturnValueAttribute() ]
ReturnType^ GetValue();
