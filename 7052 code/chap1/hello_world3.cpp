// hello_world3.cpp

using namespace System;

ref class Hello
{
    String^ greeting;

    public:
    void Greet()
    {
        Console::WriteLine(greeting + "!");
    }

    void SetGreeting(String^ newGreeting)
    {
       greeting = newGreeting;
    }
};

int main()
{
   Hello^ hello = gcnew Hello();
   hello->SetGreeting("Hello World");
   hello->Greet();
   hello->SetGreeting("Howdy");
   hello->Greet();
}

