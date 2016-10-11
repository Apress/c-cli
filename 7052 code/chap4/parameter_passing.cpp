// parameter_passing.cpp

void byvalue(int i)
{
   i += 1;
}
void byref(int& i)
{
   i += 1;
}
int main()
{
   int j = 10;
   System::Console::WriteLine("Original value: " + j);
   byvalue(j);
   System::Console::WriteLine("After byvalue: " + j);
   byref(j);
   System::Console::WriteLine("After byref: " + j);
}
